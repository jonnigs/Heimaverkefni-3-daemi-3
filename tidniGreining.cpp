#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> mostFrequentWords(string text, int k) {
    vector<string> unordered_set;
    int lengd = text.size();

    // Array þar sem hvert sæti mun geyma hlutstreng úr texta
    string *hlutstrengir = new string[lengd - k+1];

    // Fer í gegnum textan og næ í alla hlutstrengina
    for (int i=0 ; i < (lengd-(k-1)) ; i++) {
        //Setjum hlutstreng sem byrjar í stöðu "i" í texta og er af lengd "k" í hólf "i" í safni hlutstrengja
        hlutstrengir[i] = text.substr(i,k);
    }

    // Array til að halda utan um hvað hver hlutstrengur kemur of fyrir
    int *talning = new int[lengd-k+1];
    for(int i = 0; i < lengd-k+1; i++){
    	talning[i] = 1;
    }
    // for-lykkja inni í for-lykkju til að bera sérhvern hlutstreng á móti öllu nema sjálfum sér
    for (int i=0 ; i < (lengd-(k-1)) ; i++) {
        for (int m=0 ; m < (lengd-(k-1)) ; m++) {

            // if-setningin passar að við séum ekki að bera hlutstreng saman við sjálfan sig
            // og við séum ekki að taka með strenginn "búid ad telja"
            if (i != m && hlutstrengir[i].compare(hlutstrengir[m]) == 0 && hlutstrengir[i].compare("buid ad telja") != 0) {
            	// cout << talning[i] << endl;
                talning[i]++;
                hlutstrengir[m] = "buid ad telja";
            }
        }
    }
    // Nú ætti talning að vera með upplýsingar um hvað hver hlutstrengur kemur oft fyrir í texta, viljum því MAX
    // Byrjum á að setja fyrsta gildið sem það stærðsta, ef það er svo ekki stærðst þá verður því skipt út
    int max = talning[0];

    for(int i = 1; i<lengd-(k-1); i++) {
        if(talning[i] > max && (hlutstrengir[i]).compare("buid ad telja") != 0) {
        max = talning[i];
        }
     }

    // Fer nú í gegnum array-inn hlutstrengir og set inn þá sem að hafa gildi
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
    // Fáum inn textastreng.
    cout << "Sladu inn streng af stofum" << endl;
    string text;
    cin >> text;

    // Fáum inn hvaða lengd af hlutstrengjum við viljum.
    cout << "Hvad viltu leita af longum hlutstrengjum? " << endl;
    int k;
    cin >> k;

    // Keyrum fallið að ofan og skilum útkomunni.
    vector<string> lausn = mostFrequentWords(text, k);
    cout << "Algengustu strengir af lengd k eru: " << endl;
    for (int i=0 ; i < lausn.size() ; i++){
        cout << lausn[i] << endl;
    }

    return 0;
}
