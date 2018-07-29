#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<string>
#include<set>


using namespace std;
vector<vector<vector<float>>> ultimate;
vector<float> coffs;
vector<vector<float>>D;
vector<string> varsIndex;
vector<vector<pair<float, string>>> v;
vector <string>prober_eqns;



//Function to split the input
size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

	return strs.size();
}




bool search(int h, float coff, string s) {


	for (int l = 0; l<v[h].size(); l++) {
		if (v[h][l].second == s) {

			v[h][l].first += coff;
			return true;
		}

	}


	return false;


}

vector<string> properForm(vector<vector<pair<float, string>>> vec)
{
	vector<string> backed;

	for (int i = 0; i < vec.size(); i++) {
		string eqn = "";
		string cons;
		for (int j = 0; j < vec[i].size(); j++) {
			std::ostringstream ss;
			if (vec[i][j].second == "constant")
			{
				float f = -vec[i][j].first;

				std::ostringstream ss;
				ss << f;
				cons = (ss.str());
				continue;
			}
			ss << vec[i][j].first;
			if ((j != 0 && vec[i][j].first > 0) || vec[i][j].first == 0) {
				eqn += "+";
			}

			eqn += (ss.str()) + vec[i][j].second;
		}
		eqn += "=" + cons;
		backed.push_back(eqn);


	}
	return backed;
}
int num_vars() {
	set <string>s;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++) {

			s.insert(v[i][j].second);

		}



	}

	return s.size() - 1;





}
void	equation(int x) {
	cout << prober_eqns[x - 1];

}
void column(string s) {

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++) {

			if (v[i][j].second == s) {

				cout << v[i][j].first << endl;
			}
		}



	}

}
void add(int a, int b) {
	a--, b--;
	vector<vector<pair<float, string>>> temp;
	temp.resize(1);
	set<string>s;
	for (int i = 0; i < v[a].size(); i++) {
		if (s.find(v[a][i].second) == s.end()) {
			bool inBoth = 0;
			for (int j = 0; j < v[b].size(); j++) {
				if (v[b][j].second == v[a][i].second) {
					s.insert(v[b][j].second);
					inBoth = 1;
					float t = v[b][j].first + v[a][i].first;
					if(t!=0)
					temp[0].push_back(make_pair(v[b][j].first + v[a][i].first, v[b][j].second));

				}
			}
			if (inBoth == 0) {
				float t = v[a][i].first + v[a][i].first;
				if (t != 0)
				temp[0].push_back(make_pair(v[a][i].first, v[a][i].second));
			}

		}
	}
	for (int i = 0; i < v[b].size(); i++) {
		if (s.find(v[b][i].second) == s.end()) {
			bool inBoth = 0;
			for (int j = 0; j < v[a].size(); j++) {
				if (v[a][j].second == v[b][i].second) {
					s.insert(v[a][j].second);
					inBoth = 1;
					float t = v[b][j].first + v[a][i].first;
					if (t != 0)
					temp[0].push_back(make_pair(v[b][j].first + v[a][i].first, v[b][j].second));

				}
			}
			if (inBoth == 0) {
				float t = v[b][i].first;
				if (t != 0)

				temp[0].push_back(make_pair(v[b][i].first, v[b][i].second));
			}

		}
	}
	vector<string>temp2 = properForm(temp);


	cout << temp2[0] << endl;



}
void substract(int a, int b) {
	a--, b--;
	vector<vector<pair<float, string>>> temp;
	temp.resize(1);
	set<string>s;
	for (int i = 0; i < v[a].size(); i++) {
		if (s.find(v[a][i].second) == s.end()) {
			bool inBoth = 0;
			for (int j = 0; j < v[b].size(); j++) {
				if (v[b][j].second == v[a][i].second) {
					s.insert(v[b][j].second);
					inBoth = 1;
					float t = -v[b][j].first + v[a][i].first;
					if(t!=0)
					temp[0].push_back(make_pair(-v[b][j].first + v[a][i].first, v[b][j].second));

				}
			}
			if (inBoth == 0) {
				float t =  v[a][i].first;
				if (t != 0)
				temp[0].push_back(make_pair(v[a][i].first, v[a][i].second));
			}

		}
	}
	for (int i = 0; i < v[b].size(); i++) {
		if (s.find(v[b][i].second) == s.end()) {
			bool inBoth = 0;
			for (int j = 0; j < v[a].size(); j++) {
				if (v[a][j].second == v[b][i].second) {
					s.insert(v[a][j].second);
					inBoth = 1;
					float t = -v[b][j].first + v[a][i].first;
					if (t != 0)
					temp[0].push_back(make_pair(-v[b][j].first + v[a][i].first, v[b][j].second));

				}
			}
			if (inBoth == 0) {
				float t = -v[b][i].first;
				if (t != 0)
				temp[0].push_back(make_pair(-v[b][i].first, v[b][i].second));
			}

		}
	}
	vector<string>temp2 = properForm(temp);


	cout << temp2[0] << endl;



}

void substitute(string s, int a, int b) {
	a--, b--;
	int pos;

	float multiplicationFactor;
	for (int i = 0; i < v[a].size(); i++) {
		if (v[a][i].second == s) {
			multiplicationFactor = v[a][i].first;
			pos = i;
		}
	}
	vector<vector<pair<float, string>>> temp;
	temp = v;
	temp[a].erase(temp[a].begin() + pos);
	for (int i = 0; i < v[b].size(); i++) {
		if (v[b][i].second == s) {
			multiplicationFactor /= v[b][i].first;
			pos = i;
		}
	}

	temp[b].erase(temp[b].begin() + pos);
	for (int i = 0; i < temp[b].size(); i++)temp[b][i].first *= -multiplicationFactor;

	vector<vector<pair<float, string>>> tempo;
	tempo.resize(1);
	set<string>ss;
	for (int i = 0; i < temp[a].size(); i++) {
		if (ss.find(temp[a][i].second) == ss.end()) {
			bool inBoth = 0;
			for (int j = 0; j < temp[b].size(); j++) {
				if (temp[b][j].second == temp[a][i].second) {
					ss.insert(temp[b][j].second);
					inBoth = 1;
					tempo[0].push_back(make_pair(temp[b][j].first + temp[a][i].first, temp[b][j].second));

				}
			}
			if (inBoth == 0) {
				tempo[0].push_back(make_pair(temp[a][i].first, temp[a][i].second));
			}

		}
	}
	for (int i = 0; i < temp[b].size(); i++) {
		if (ss.find(temp[b][i].second) == ss.end()) {
			bool inBoth = 0;
			for (int j = 0; j < temp[a].size(); j++) {
				if (temp[a][j].second == temp[b][i].second) {
					ss.insert(temp[a][j].second);
					inBoth = 1;
					tempo[0].push_back(make_pair(temp[b][j].first + temp[a][i].first, temp[b][j].second));

				}
			}
			if (inBoth == 0) {
				tempo[0].push_back(make_pair(temp[b][i].first, temp[b][i].second));
			}

		}
	}
	vector<string>temp2 = properForm(tempo);


	cout << temp2[0] << endl;



}
void determenant() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < varsIndex.size(); j++) {
			cout << D[i][j] << "  ";

		}
		cout << endl;
	}


}

float calculate(vector<vector<float>> v) {
	float x = 0;
	if (v.size() == 2) {

		return  v[0][0] * v[1][1] - v[0][1] * v[1][0];
	}
	int sign = 1;

	for (int j = 0; j < v[0].size(); j++) {
		vector<vector<float>> temp = v;

		temp.erase(temp.begin() + 0);
		for (int h = 0; h < temp.size(); h++)temp[h].erase(temp[h].begin() + j);
		if (j % 2 == 0)sign = 1;
		else
			sign = -1;

		x += sign*v[0][j] * calculate(temp);





	}



	return x;
}

void solve() {
	int columnIndex;


	for (int k = 0; k < varsIndex.size(); k++) {

		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < varsIndex.size(); j++) {
				if (j != k)
					ultimate[k][i][j] = D[i][j];
				else
					ultimate[k][i][j] = -coffs[i];

			}

		}
	}
	for (int i = 0; i < varsIndex.size(); i++) {
		float f = calculate(ultimate[i]) / calculate(D);

		cout << varsIndex[i] << " is: " << f<<endl ;


	}
}

void var_determenant(string s) {
	int columnIndex;
	for (int i = 0; i < varsIndex.size(); i++)
		if (s == varsIndex[i])columnIndex = i;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < varsIndex.size(); j++) {
			if (j != columnIndex)
				cout << D[i][j] << "  ";
			else
				cout << -coffs[i] << "  ";

		}
		cout << endl;
	}

}





int main()

/**
TO DO
1-Handle if there a constat term   (Done)
2-Handle if the vaiables are after that equal sign (Done)
3-Handle if there is repeated variables  (Done)
4-Handle x1 & -x1   (Done)
5-Handle plus and minus signs  (Done)


UnHandled
1- Store Eqns at an array of strings at Prober form
2- Start perform the operartion


Hint: make the final Eqns Array Global and then make
function to each operaion



Optional:   U can  make enhancement by create functions



*Note:
1-I have every Variable with his Coff in Vector V (All Variables are in the left siide Eqn=0)
2-We have the Prboper form Eqns ad Proper_Eqns


**/

{



	int n;
	string eqns[100];

	cin >> n;
	v.resize(n);
	prober_eqns.resize(n);
	for (int i = 0; i<n; i++) {
		int temp = 0;
		bool secondHalf = false;
		bool justafter = 0;

		cin >> eqns[i];
		for (int j = 0; j<eqns[i].size(); j++) {

			if (eqns[i][j] == '+' || eqns[i][j] == '-' || eqns[i][j] == '=' || j == (eqns[i].size() - 1)) {


				int range = 0;
				string	sub;
				j == (eqns[i].size() - 1) ? range = j - temp + 1 : range = j - temp;
				if (temp == 0 || justafter) {
					if (justafter)justafter = 0;
					sub = eqns[i].substr(temp, range);
				}
				else
					sub = eqns[i].substr(temp - 1, range + 1);
				//cout << sub << endl;
				bool isConst = true;
				for (int k = 0; k < sub.length(); k++) {

					string coff, var;
					if (sub[k] > '9')
					{
						isConst = false;

						coff = sub.substr(0, k);

						var = sub.substr(k, sub.length());
						if (coff.length() == 1 && (coff == "+" || coff == "-"))
							coff == "+" ? coff = "1" : coff = "-1";
						if (coff.length() == 0)coff = "1";

						pair<float, string> p;
						float f = atof(coff.c_str());


						secondHalf == true ? p.first = -f : p.first = f;

						p.second = var;
						if (!search(i, p.first, p.second)) {
							v[i].push_back(p);
						}


						break;
					}




				}
				if (isConst) {


					pair<float, string> p;
					float f = atof(sub.c_str());
					secondHalf == true ? p.first = -f : p.first = f;
					p.second = "constant";
					if (!search(i, p.first, p.second)) {
						v[i].push_back(p);
					}





				}






				if (eqns[i][j] == '=') {
					secondHalf = true; justafter = 1;
				}
				temp = j + 1;
			}


		}

	}
	for (int i = 0; i<v.size(); i++) {

		sort(v[i].begin(), v[i].end(), [](auto &lh, auto &rhs) {
			return rhs.second > lh.second;
		});


	}

	/**
	for (int h = 0; h<v.size(); h++) {
	for (int l = 0; l<v[h].size(); l++) {
	pair<float, string> pp = v[h][l];

	cout << pp.first << "     " << pp.second << endl;

	}

	}
	**/



	prober_eqns = properForm(v);
	/*/
	for (int i = 0; i < prober_eqns.size(); i++) {
		cout << prober_eqns[i] << endl;
	}
	**/
	string operation;
	int numOfVars = num_vars();

	varsIndex.resize(numOfVars);
	set<string>  varsName;
	int cnt = 0;
	// This is to know the index of each var for level 3
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j].second != "constant"&&varsName.find(v[i][j].second) == varsName.end()) {

				varsIndex[cnt] = v[i][j].second;
				varsName.insert(v[i][j].second);
				cnt++;
			}
			if (v[i][j].second == "constant")coffs.push_back(v[i][j].first);
		}
	}
	sort(varsIndex.begin(), varsIndex.end());

	// This is to resize the ultimate vector which is vector that contains all determanes (D_x1,D_x2,.....)
	int size = varsIndex.size();
	ultimate.resize(size);
	for (int i = 0; i < size; i++)
	{
		ultimate[i].resize(varsIndex.size());
		for (int j = 0; j < size; j++)
		{
			ultimate[i][j].resize(varsIndex.size());
		}
	}

	//for (auto i : varsIndex)cout << i;
	// This is to make coffecient matrix D for level 3
	D.resize(n);
	for (int i = 0; i < n; ++i)
		D[i].resize(numOfVars);
	for (int i = 0; i < v.size(); i++) {

		for (int j = 0; j < varsIndex.size(); j++) {
			for (int k = 0; k < v[i].size(); k++) {
				if (v[i][k].second == varsIndex[j]) {
					D[i][j] = v[i][k].first;

					break;
				}
				// here I implement the coof vector
				else if (v[i][k].second == "constant") {
					coffs.push_back(v[i][k].first);

				}
				else if (k == v[i].size() - 1)
					D[i][j] = 0;

			}


		}
		cout << endl;
	}
	while (true)
	{
		getline(cin, operation);

		std::vector<std::string> input;

		split(operation, input, ' ');

		if (input[0] == "quit")break;

		else if (input[0] == "num_vars")cout << num_vars();
		else if (input[0] == "equation") {
			int i;
			i = stoi(input[1]);
			equation(i);

		}
		else if (input[0] == "column") {
			string v = input[1];
			column(v);
		}
		else if (input[0] == "add") {
			int a, b;
			a = stoi(input[1]);
			b = stoi(input[2]);

			add(a, b);

		}
		else if (input[0] == "subtract") {
			int a, b;
			a = stoi(input[1]);
			b = stoi(input[2]);
			substract(a, b);

		}
		else if (input[0] == "substitute") {

			string s;
			int a, b;
			s = input[1];
			a = stoi(input[2]);
			b = stoi(input[3]);

			substitute(s, a, b);
		}
		else if (input[0] == "D") {

			if (input.size() == 1)
				determenant();
			else
				var_determenant(input[1]);


		}
		else if (input[0] == "D_value") {
			float ans = calculate(D);
			cout << ans << " ";
		}
		else if (input[0] == "solve") {
			float d = calculate(D);
			if (d == 0)cout << "Infinite solutions";
			else if (n < num_vars())cout << "No Solution";
			else

			solve();
		}



	}








	return 0;
}



