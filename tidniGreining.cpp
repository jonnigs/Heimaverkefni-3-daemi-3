#include <iostream>
#include <string>
#include <vector>


using namespace std;

string mostFrequentWords(string text, int k) {
    vector<string> mengi; //unordered_set;
    int lengd = text.size();

    // Array �ar sem hvert s�ti mun geyma hlutstreng �r texta
    string hlutstrengir[lengd-k+1];

    // Fer � gegnum textan og n� � alla hlutstrengina
    for (int i=0 ; i < (lengd-k+1) ; i++) {
        //Setjum hlutstreng sem byrjar � st��u "i" � texta og er af lengd "k" � h�lf "i" � safni hlutstrengja
        hlutstrengir[i] = text.substr (i,k);
    }
    // Array til a� halda utan um hva� hver hlutstrengur kemur of fyrir
    int talning[lengd-k+1];

    // for-lykkja inni � for-lykkju til a� bera s�rhvern hlutstreng � m�ti �llu nema sj�lfum s�r
    for (int i=0 ; i < (lengd-k+1) ; i++) {
        for (int m=0 ; i < (lengd-k+1) ; m++) {
            if (hlutstrengir[i] == hlutstrengir[m] && i != m) {
                talning[i]++;
                hlutstrengir[m] = "b�i� a� telja";
            }
        }
    }

    // N� �tti talning a� vera me� uppl�singar um hva� hver hlutstrengur kemur oft fyrir � texta, viljum �v� MAX
    // Byrjum � a� setja fyrsta gildi� sem �a� st�r�sta, ef �a� er svo ekki st�r�st �� ver�ur �v� skipt �t
    int max = talning[0];

    for(int i = 1; i<lengd-k+1; i++) {
        if(talning[i] > max && hlutstrengir[i] != "b�i� a� telja") {
        max = talning[i];
        }
     }

    int s=0;
    // Fer n� � gegnum array-inn hlutstrengir og set inn �� sem a� hafa gildi
    for (int i = 0 ; i < lengd-k+1 ; i++) {
        if (talning[i] == max) {
            mengi[s] = hlutstrengir[i];
            s++;
        }
    }
    string test = mengi[0];
    return test; //unordered_set;
}

int main() {
    // F�um inn textastreng.
    cout << "Sladu inn streng af stofum" << endl;
    string text;
    cin >> text;

    // F�um inn hva�a lengd af hlutstrengjum vi� viljum.
    cout << "Hvad viltu leita af longum hlutstrengjum? " << endl;
    int k;
    cin >> k;

    // Keyrum falli� a� ofan og skilum �tkomunni.
    string lausn;
    lausn = mostFrequentWords(text, k);
    cout << "Algengustu strengir af lengd k eru: " << lausn << endl;
    //for (int i=0 ; i < 5 ; 1++){
    //cout << lausn[i];
    //}

    return 0;
}
