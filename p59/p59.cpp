#include <bits/stdc++.h>

using namespace std;

tuple<int, vector<string>, int> translate(const vector<int>& text, array<int, 3> cipher, const set<string>& knowledge)
{
    string current_string;
    vector<string> all_strings;
    int len = (int) text.size();
    int ans = 0;
    int soma = 0;
    for(int i = 0; i < len; ++i)
    {
        int cur_val = ( text[i] ^ cipher[i % 3] );
        char c = cur_val;
        soma += c;
        if( c == ' ' )
        {
            if( !current_string.empty() )
            {
                all_strings.push_back( current_string );
                if( knowledge.find( current_string ) != knowledge.end() ) ans++; 
                current_string.clear();
            }
        }
        else
        {
            current_string += c;
        }
    }
    all_strings.push_back( current_string );
    if( knowledge.find( current_string ) != knowledge.end() ) ++ans;

    return make_tuple(ans, all_strings, soma);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ifstream in1("common.txt");
    ifstream in2("p59_cipher.txt");
    
    vector< int > text;

    set<string> knowledge;
    string s;

    while(in1 >> s)
    {
        knowledge.insert(s);
    }

    pair<int, int> range = {97, 122};
    
    while(in2 >> s)
    {
        cout << "estou lendo a string = " << s << endl;
        cout << "estou inserindo no vetor o valor = " << stoi(s) << endl;
        text.push_back( stoi(s) );
    }

    // vamos tentar todas as cifras de 3 caracteres
    // e retornar a que decriptar o texto e encontrar mais palavras comuns
    int best = 0;
    vector<string> decrypt;
    int resposta = 0;
    for(int i = range.first; i <= range.second; ++i)
    {
        for(int j = range.first; j <= range.second; ++j)
        {
            for(int k = range.first; k <= range.second; ++k)
            {
                auto result = translate(text, {i, j, k}, knowledge);
                if( get<0>(result) > best)
                {
                    best = get<0>(result);        
                    decrypt = get<1>(result); 
                    resposta = get<2>(result);
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    for( const auto& x : decrypt) cout << x << " ";
    cout << "resposta = " << resposta << endl;
    return 0;
}
