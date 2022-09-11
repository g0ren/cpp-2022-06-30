#include <iostream>
#include <map>
#include <vector>
using namespace std;

class C {
protected:
	map<string, int> variables;
public:
	void set(string name, int value) {
		this->variables[name] = value;
	}
	void mult(string name, double factor = 1) {
		if (this->variables[name])
			cout << this->variables[name] * factor << endl;
		else
			cout << "Unknown variable!" << endl;
	}

	void plus(string name, double term = 0) {
		if (this->variables[name])
			cout << this->variables[name] + term << endl;
		else
			cout << "Unknown variable!" << endl;
	}

	int get(string name) {
		if (this->variables[name]) {
			return this->variables[name];
		} else {
			cout << "Unknown variable!" << endl;
			return 0;
		}
	}

	int* getLink(string name) {
		if (this->variables[name]) {
			return &(this->variables[name]);
		} else {
			cout << "Unknown variable!" << endl;
			return nullptr;
		}
	}

	int valByLink(int *link) {
		for (auto i : this->variables) {
			if (&variables[i.first] == link)
				return i.second;
		}
		cout << "Unknown variable!" << endl;
		return 0;
	}

	string nameByLink(int *link) {
		for (auto i : this->variables)
			if (&variables[i.first] == link)
				return i.first;
		cout << "Unknown variable!" << endl;
		return "";
	}
};

class CPP: public C {
public:
	struct _class {
		string name;
		vector<pair<string, int>> vars;
		_class(string name) {
			this->name = name;
		}
		void listVars() {
			for (auto p : vars) {
				cout << p.first << " " << p.second << endl;
			}
		}
	};

	map<string, _class*> classes;

	_class makeClass(string name) {
		_class tmp(name);
		classes[name] = &tmp;
		return tmp;
	}

	void addToClass(string cname, string vname) {
		if (!this->variables[vname])
			cout << "Unknown variable!" << endl;
		else if (!this->classes[cname])
			cout << "Unknown class!" << endl;
		else
			classes[cname]->vars.push_back(make_pair(vname, variables[vname]));
	}

	void listClasses() {
		for (auto c : classes) {
			cout << c.first << ":" << endl;
			c.second->listVars();
		}
	}
};

int main() {
	C c;
	c.set("i", 1);
	c.set("m", 5);
	c.set("n", 3);
	c.set("height of Empire State Building", 380);
	c.mult("n");
	c.plus("m", 10.113);
	c.plus("m", c.get("n"));
	cout << c.valByLink(c.getLink("i")) << endl;
	cout << c.nameByLink(c.getLink("height of Empire State Building")) << endl;

	CPP cpp;
	cpp.set("a", 12);
	cpp.set("b", 13);
	cpp.set("c", 22);
	cpp.set("Orwell", 1984);
	cpp.set("Bradbury", 451);
	cpp.set("Voynovich", 2042);
	cpp.mult("Orwell", 1);
	cpp.makeClass("Dystopia");
	cpp.addToClass("Dystopia", "Orwell");
	cpp.addToClass("Dystopia", "Bradbury");
	cpp.addToClass("Dystopia", "Voynovich");
	cpp.listClasses();

	return 0;
}
