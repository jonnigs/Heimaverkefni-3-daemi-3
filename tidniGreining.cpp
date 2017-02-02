#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> mostFrequentWords(string text, int k) {
    vector<string> unordered_set;
    int lengd = text.size();

    // Array �ar sem hvert s�ti mun geyma hlutstreng �r texta
    string *hlutstrengir = new string[lengd - k+1];

    // Fer � gegnum textan og n� � alla hlutstrengina
    for (int i=0 ; i < (lengd-(k-1)) ; i++) {
        //Setjum hlutstreng sem byrjar � st��u "i" � texta og er af lengd "k" � h�lf "i" � safni hlutstrengja
        hlutstrengir[i] = text.substr(i,k);
    }

    // Array til a� halda utan um hva� hver hlutstrengur kemur of fyrir
    int *talning = new int[lengd-k+1];
    for(int i = 0; i < lengd-k+1; i++){
    	talning[i] = 1;
    }
    // for-lykkja inni � for-lykkju til a� bera s�rhvern hlutstreng � m�ti �llu nema sj�lfum s�r
    for (int i=0 ; i < (lengd-(k-1)) ; i++) {
        for (int m=0 ; m < (lengd-(k-1)) ; m++) {

            // if-setningin passar a� vi� s�um ekki a� bera hlutstreng saman vi� sj�lfan sig
            // og vi� s�um ekki a� taka me� strenginn "b�id ad telja"
            if (i != m && hlutstrengir[i].compare(hlutstrengir[m]) == 0 && hlutstrengir[i].compare("buid ad telja") != 0) {
            	// cout << talning[i] << endl;
                talning[i]++;
                hlutstrengir[m] = "buid ad telja";
            }
        }
    }
    // N� �tti talning a� vera me� uppl�singar um hva� hver hlutstrengur kemur oft fyrir � texta, viljum �v� MAX
    // Byrjum � a� setja fyrsta gildi� sem �a� st�r�sta, ef �a� er svo ekki st�r�st �� ver�ur �v� skipt �t
    int max = talning[0];

    for(int i = 1; i<lengd-(k-1); i++) {
        if(talning[i] > max && (hlutstrengir[i]).compare("buid ad telja") != 0) {
        max = talning[i];
        }
     }

    // Fer n� � gegnum array-inn hlutstrengir og set inn �� sem a� hafa gildi
    for (int i = 0 ; i < lengd-(k-1) ; i++) {
        if (talning[i] == max) {
            unordered_set.push_back(hlutstrengir[i]);
        }
    }
    cout << "****" << endl;
    delete [] talning;
    delete [] hlutstrengir;
    return unordered_set;
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
    vector<string> lausn = mostFrequentWords(text, k);
    cout << "Algengustu strengir af lengd k eru: " << endl;
    for (int i=0 ; i < lausn.size() ; i++){
        cout << lausn[i] << endl;
    }

    return 0;
}
