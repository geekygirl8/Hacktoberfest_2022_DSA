// Name : Nikita
// Github id: geekygirl8


class Solution {
public:
string longestPalindrome(string s)
{
	int n = s.length();
	string newStr(2 * n + 1, '0');
	int i = 0;
	newStr[i++] = '#';
	for (char c : s)
	{
		newStr[i++] = c;
		newStr[i++] = '#';
	}

	vector<int> p(2 * n + 1, 0);
	int center = 0, right = 0;

	int longestLength = 0, longestCenter = 0;

	for (i = 0; i < newStr.length(); i++)
	{

		int mirror = 2 * center - i;

		if (right > i)
		{
			p[i] = min(p[mirror], right - i);
		}

		int a = i + (p[i] + 1);
		int b = i - (p[i] + 1);

		while (b >= 0 && a < newStr.length() && newStr[a] == newStr[b])
		{
			b--;
			a++;
			p[i]++;
		}

		if (p[i] >= longestLength)
		{ 
			longestCenter = i;
			longestLength = p[i];
		}

		if (i + p[i] > right)
		{
			center = i;
			right = i + p[i];
		}
	}
    string ans="";
        for(int i=longestCenter-longestLength;i<=longestCenter+longestLength;i++)
            if(newStr[i]!='#')
            ans.push_back(newStr[i]);
        return ans;
	}
};
