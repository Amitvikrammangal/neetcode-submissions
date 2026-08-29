class Solution {
public:

    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);
        rankv.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // email -> account index
        unordered_map<string, int> mp;

        // Step 1: Connect accounts having common email
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (mp.find(email) == mp.end()) {
                    mp[email] = i;
                }
                else {
                    unite(i, mp[email]);
                }
            }
        }

        // Step 2: Put emails into their root account
        unordered_map<int, vector<string>> merged;

        for (auto it : mp) {

            string email = it.first;
            int account = it.second;

            int root = find(account);

            merged[root].push_back(email);
        }

        // Step 3: Create answer
        vector<vector<string>> ans;

        for (auto &it : merged) {

            int root = it.first;

            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> temp;

            temp.push_back(accounts[root][0]);

            for (string email : emails)
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};