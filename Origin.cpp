#include<iostream>
using namespace std;

enum class PhysicalGender
{
    male,
    female
};

struct Human
{
    string name;
    PhysicalGender gender;
};

class CivilCode
{
public:
    using Partner = pair<Human, Human>;

    bool isMarried(Partner user)
    {
        if( isMale(user.first) != isFemale(user.second) )
        {
            return false; //same gender
        }
        //... some checks
        return true;
    }
    
    bool isMale(Human user)
    {
        return user.gender == PhysicalGender::male;
    }

    bool isFemale(Human user)
    {
        return user.gender == PhysicalGender::female;
    }
};

class RuleA: private CivilCode
{
public:
    bool check(Human a, Human b)
    {
        if( isMarried({a, b}) )
        {
            return true;
        }
        return false;
    }
};

class RuleB: private CivilCode
{
public:
    bool check(Human a, Human b)
    {
        if( isMarried({a, b}) )
        {
            return true;
        }
        return false;
    }
};

const char* getGender(Human a)
{
    return a.gender==PhysicalGender::male ? "male" : "female" ;
}

int main()
{
    Human h[4] = { 
        {"John"    , PhysicalGender::male},
        {"Alice"   , PhysicalGender::female},
        {"Betty"   , PhysicalGender::female},
        {"Caroline", PhysicalGender::female}
    };
    
    RuleA rule_a;
    RuleB rule_b;
    
    for(int i=0;i<4;i+=2)
    {
        cout<<h[i  ].name<<" is "<<getGender(h[i  ])<<'\n';
        cout<<h[i+1].name<<" is "<<getGender(h[i+1])<<'\n';
        
        cout<<"Did they accept rule A ? "<<boolalpha<<rule_a.check(h[i  ], h[i+1])<<endl;
        cout<<"Did they accept rule B ? "<<boolalpha<<rule_b.check(h[i  ], h[i+1])<<endl;
        
        cout<<"\n===============\n";
    }
}


