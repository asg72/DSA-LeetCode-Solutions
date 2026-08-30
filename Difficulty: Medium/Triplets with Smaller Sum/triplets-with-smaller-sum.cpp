class Solution {
	public:
	int countTriplets(int target, vector<int>& arr) {
		// code here
		int n = arr.size();
		
		sort(arr.begin(), arr.end());
		int count = 0;
		for (int i = 0; i<n - 2; ++i) {
			int j = i + 1;
			int k = n - 1;
			
			while (j < k) {
				int sum = arr[i]+arr[j]+arr[k];
				
				if (sum < target) {
					count += (k - j);
					j++;
				} else {
					k--;
				}
			}
		}
		
		return count;
	}
};
