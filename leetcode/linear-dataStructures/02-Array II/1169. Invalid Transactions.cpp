class Solution {
public:

    struct transaction{
        string name;
        int time;
        int amount;
        string city;

        bool operator==(const transaction& other) const{
        return name == other.name && time == other.time && amount == other.amount && city == other.city;
        }
    };

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector <transaction> parsedTransactions;
        vector <bool> isInvalid(transactions.size(), false);
        unordered_map <string, vector <transaction>> nameToTransactions;

        // parse transactions; store then in a vector of transactions objects;
        for(const string& transaction: transactions){
            size_t pos = 0; 
            size_t found = transaction.find(',', pos);
            string name = transaction.substr(pos, found - pos);
            pos = found + 1;

            found = transaction.find(',', pos);
            int time = stoi(transaction.substr(pos, found - pos));
            pos = found + 1;

            found = transaction.find(',', pos);
            int amount = stoi(transaction.substr(pos, found - pos));
            pos = found + 1;

            string city = transaction.substr(pos);
            parsedTransactions.push_back({name, time, amount, city});
            nameToTransactions[name].push_back({name, time, amount, city});
        }    

        // invalid transactions
        for(int i = 0; i < parsedTransactions.size(); i++){
            const transaction& curr = parsedTransactions[i];

            if(curr.amount > 1000)
                isInvalid[i] = true;

            vector <transaction>& sameNameTransactions = nameToTransactions[curr.name];

            for(const transaction& other: sameNameTransactions){
                if(other.city != curr.city && abs(other.time - curr.time) <= 60){
                    isInvalid[i] = true;
                    isInvalid[distance(parsedTransactions.begin(), find(parsedTransactions.begin(), parsedTransactions.end(), other))] = true;
                }
            }
        }

        // collect invalid transactions as stirngs
        vector <string> result;
        for(int i = 0; i < transactions.size(); i++)
            if(isInvalid[i])
                result.push_back(transactions[i]);

        return result;
    }
};
