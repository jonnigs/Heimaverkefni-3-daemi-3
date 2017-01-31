#include <iostream>
#include <string>
#include <vector>


using namespace std;

string mostFrequentWords(string text, int k) {
    vector<string> mengi; //unordered_set;
    int lengd = text.size();

    // Array þar sem hvert sæti mun geyma hlutstreng úr texta
    string hlutstrengir[lengd-k+1];

    // Fer í gegnum textan og næ í alla hlutstrengina
    for (int i=0 ; i < (lengd-k+1) ; i++) {
        //Setjum hlutstreng sem byrjar í stöðu "i" í texta og er af lengd "k" í hólf "i" í safni hlutstrengja
        hlutstrengir[i] = text.substr (i,k);
    }
    // Array til að halda utan um hvað hver hlutstrengur kemur of fyrir
    int talning[lengd-k+1];

    // for-lykkja inni í for-lykkju til að bera sérhvern hlutstreng á móti öllu nema sjálfum sér
    for (int i=0 ; i < (lengd-k+1) ; i++) {
        for (int m=0 ; i < (lengd-k+1) ; m++) {
            if (hlutstrengir[i] == hlutstrengir[m] && i != m) {
                talning[i]++;
                hlutstrengir[m] = "búið að telja";
            }
        }
    }

    // Nú ætti talning að vera með upplýsingar um hvað hver hlutstrengur kemur oft fyrir í texta, viljum því MAX
    // Byrjum á að setja fyrsta gildið sem það stærðsta, ef það er svo ekki stærðst þá verður því skipt út
    int max = talning[0];

    for(int i = 1; i<lengd-k+1; i++) {
        if(talning[i] > max && hlutstrengir[i] != "búið að telja") {
        max = talning[i];
        }
     }

    int s=0;
    // Fer nú í gegnum array-inn hlutstrengir og set inn þá sem að hafa gildi
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
    // Fáum inn textastreng.
    cout << "Sladu inn streng af stofum" << endl;
    string text;
    cin >> text;

    // Fáum inn hvaða lengd af hlutstrengjum við viljum.
    cout << "Hvad viltu leita af longum hlutstrengjum? " << endl;
    int k;
    cin >> k;

    // Keyrum fallið að ofan og skilum útkomunni.
    string lausn;
    lausn = mostFrequentWords(text, k);
    cout << "Algengustu strengir af lengd k eru: " << lausn << endl;
    //for (int i=0 ; i < 5 ; 1++){
    //cout << lausn[i];
    //}

    return 0;
}
