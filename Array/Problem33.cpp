// Problem 33 - Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
// Pronlem link - https://www.codingninjas.com/studio/problems/majority-element_6915220?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=PROBLEM

// BeuteForce Approach => TC = O(n2)
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}

//Better Approach => TC -  O(N*logN)
vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    //declaring a map:
    map<int, int> mpp;

    // least occurrence of the majority element:
    int mini = int(n / 3) + 1;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;

        //checking if v[i] is
        // the majority element:
        if (mpp[v[i]] == mini) {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2) break;
    }

    return ls;
}



// Optimal Solution => TC = O(n)
#include <bits/stdc++.h>
vector<int> majorityElement(vector<int> v) {
	// Write your code here
	int cnt1 =0, cnt2 =0;
	int el1 = INT_MIN;
	int el2 = INT_MIN;
	for(int i=0; i<v.size(); i++){
		if(cnt1 == 0 && v[i]!=el2){
			cnt1 =1;
			el1 = v[i];
		}
		else if(cnt2 == 0 && v[i]!=el1){
			cnt2 =1;
			el2 = v[i];
		}
		else if(v[i]==el1) cnt1++;
		else if(v[i]==el2) cnt2++;
		else{
			cnt1--;
			cnt2--;
		}
	}
	vector<int> ls;
	cnt1 =0; cnt2=0;
	for(int i=0; i<v.size(); i++){
		if(el1 == v[i]) cnt1++;
		if(el2 == v[i]) cnt2++;
	}
	int mini = (int)(v.size()/3)+1;
	if(cnt1>= mini) ls.push_back(el1);
	if(cnt2>= mini) ls.push_back(el2);
	sort(ls.begin(), ls.end());
	return ls;
}



