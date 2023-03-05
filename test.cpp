#include <bits/stdc++.h>
using namespace std;
// #include"rdb.h"

class Attr
{public: string dtype;
public:
    // Base class for attributes
     Attr(string s):dtype(s){}
     virtual void printattritube()=0;
    virtual bool operator==(const Attr &right) const = 0;
    virtual bool operator!=(const Attr &right) const = 0;
    virtual bool operator<(const Attr &right) const = 0;
    virtual bool operator<=(const Attr &right) const = 0;
    virtual bool operator>(const Attr &right) const = 0;
    virtual bool operator>=(const Attr &right) const = 0;
    // virtual ostream& operator<< (std::ostream& os) const = 0;
    virtual Attr* clone() const=0;
    friend ostream& operator<<(ostream &os,  Attr* attr) ;
    virtual ~Attr() {}
};
   

// Derived class for integer attributes
class IntAttr : public Attr
{
public:
    int value_;
public:
    IntAttr(int value,string d="int") : value_(value), Attr(d) {}

    void printattritube(){cout<<value_;}

    bool operator==(const Attr &right) const override
    {
        const IntAttr *rightInt = dynamic_cast<const IntAttr *>(&right);
        if (rightInt == nullptr)
            return false;
        return (value_ == rightInt->value_);
    }

    bool operator!=(const Attr &right) const override
    {
        const IntAttr *rightInt = dynamic_cast<const IntAttr *>(&right);
        if (rightInt == nullptr)
            return false;
        return (value_ != rightInt->value_);
    }

    bool operator<(const Attr &right) const override
    {
        const IntAttr *rightInt = dynamic_cast<const IntAttr *>(&right);
        if (rightInt == nullptr)
            return false;
        return (value_ < rightInt->value_);
    }

    bool operator<=(const Attr &right) const override
    {
        const IntAttr *rightInt = dynamic_cast<const IntAttr *>(&right);
        if (rightInt == nullptr)
            return false;
        return (value_ <= rightInt->value_);
    }

    bool operator>(const Attr &right) const override
    {
        const IntAttr *rightInt = dynamic_cast<const IntAttr *>(&right);
        if (rightInt == nullptr)
            return false;
        return (value_ > rightInt->value_);
    }

    bool operator>=(const Attr &right) const override
    {
        const IntAttr *rightInt = dynamic_cast<const IntAttr *>(&right);
        if (rightInt == nullptr)
            return false;
        return (value_ >= rightInt->value_);
    }

    IntAttr* clone() const override {
        return new IntAttr(*this);  // create a new object with the same value
    }

     ~IntAttr(){}

};

// Derived class for string attributes
class StringAttr : public Attr
{
public:
    string value_;
public:
    StringAttr(string value,string d="string") : value_(value),Attr(d) {}
    
    void printattritube(){cout<<value_;}

     bool operator==(const Attr &right) const override
    {
        const StringAttr *rightString = dynamic_cast<const StringAttr *>(&right);
        if (rightString == nullptr)
            return false;
        return (value_ == rightString->value_);
    }

    bool operator!=(const Attr &right) const override
    {
        const StringAttr *rightString = dynamic_cast<const StringAttr *>(&right);
        if (rightString == nullptr)
            return false;
        return (value_ != rightString->value_);
    }

    bool operator<(const Attr &right) const override
    {
        const StringAttr *rightString = dynamic_cast<const StringAttr *>(&right);
        if (rightString == nullptr)
            return false;
        return (value_ < rightString->value_);
    }

    bool operator<=(const Attr &right) const override
    {
        const StringAttr *rightString = dynamic_cast<const StringAttr *>(&right);
        if (rightString == nullptr)
            return false;
        return (value_ <= rightString->value_);
    }

    bool operator>(const Attr &right) const override
    {
        const StringAttr *rightString = dynamic_cast<const StringAttr *>(&right);
        if (rightString == nullptr)
            return false;
        return (value_ > rightString->value_);
    }

    bool operator>=(const Attr &right) const override
    {
        const StringAttr *rightString = dynamic_cast<const StringAttr *>(&right);
        if (rightString == nullptr)
            return false;
        return (value_ >= rightString->value_);
    }

    StringAttr* clone() const override {
        return new StringAttr(*this);  // create a new object with the same value
    }

   
    ~StringAttr(){}
};

// Derived class for float attributes
class FloatAttr : public Attr
{
public:
    float value_;
public:
    FloatAttr(float value,string d="float") : value_(value),Attr(d) {}

    void printattritube(){cout<<value_;}


    bool operator==(const Attr &right) const override
    {
        const FloatAttr *rightFloat = dynamic_cast<const FloatAttr *>(&right);
        if (rightFloat == nullptr)
            return false;
        return (value_ == rightFloat->value_);
    }

    bool operator!=(const Attr &right) const override
    {
        const FloatAttr *rightFloat = dynamic_cast<const FloatAttr *>(&right);
        if (rightFloat == nullptr)
            return false;
        return (value_ != rightFloat->value_);
    }

    bool operator<(const Attr &right) const override
    {
        const FloatAttr *rightFloat = dynamic_cast<const FloatAttr *>(&right);
        if (rightFloat == nullptr)
            return false;
        return (value_ < rightFloat->value_);
    }

    bool operator<=(const Attr &right) const override
    {
        const FloatAttr *rightFloat = dynamic_cast<const FloatAttr *>(&right);
        if (rightFloat == nullptr)
            return false;
        return (value_ <= rightFloat->value_);
    }

    bool operator>(const Attr &right) const override
    {
        const FloatAttr *rightFloat = dynamic_cast<const FloatAttr *>(&right);
        if (rightFloat == nullptr)
            return false;
        return (value_ > rightFloat->value_);
    }

    bool operator>=(const Attr &right) const override
    {
        const FloatAttr *rightFloat = dynamic_cast<const FloatAttr *>(&right);
        if (rightFloat == nullptr)
            return false;
        return (value_ >= rightFloat->value_);
    }

    FloatAttr* clone() const override {
        return new FloatAttr(*this);  // create a new object with the same value
    }

    ~FloatAttr(){}
};

     ostream& operator<< (ostream& os,const IntAttr &a)  {
        os << a.value_;
        return os;
    }

       ostream& operator<< (ostream& os,const StringAttr &a)  {
        os << a.value_;
        return os;
    }

       ostream& operator<< (ostream& os,const FloatAttr &a)  {
        os << a.value_;
        return os;
    }


ostream& operator<<(ostream &os, Attr* attr){
   

         if(attr->dtype=="int") {IntAttr* p1=dynamic_cast<IntAttr*>(attr);os<<p1->value_;}
    else if(attr->dtype=="float"){ FloatAttr* p1=dynamic_cast<FloatAttr*>(attr);os<<p1->value_;}
    else { StringAttr* p1=dynamic_cast <StringAttr*> (attr);os<<p1->value_;}
    return os;

}


class Record{
public:
    vector<Attr *> attrptr;
public:
    Record(int n);
    Record(const vector<Attr*>& attrs);
    int size() const;
    void pushAttr(Attr *attr);
    void removeAttr(const int i);
    void clearAttrs();
    vector<Attr*> getAttr() const;
    Attr* getAttrbyindex(const int i);
    void setAttr(const int i, Attr *attr);
    bool operator==(const Record &right) const;
    // friend ostream& operator<<(ostream &os, const Record& record) ;
    void printrecord();
    ~Record();
    friend class Relation;
};


Record::Record(int n){
    
}

// Constructor
Record::Record(const vector<Attr *> &attrs)
{
    attrptr = attrs;
}

// Destructor
Record::~Record()
{
    for (auto &attr : attrptr)
    {
        delete attr;
    }
}

// Size method
int Record::size() const
{
    return attrptr.size();
}

// PushAttr method
void Record::pushAttr(Attr *attr)
{
    if(attr==NULL) return;
    attrptr.push_back(attr);
}

// removeAttr method
void Record::removeAttr(const int i)
{
    delete attrptr[i];
    attrptr.erase(attrptr.begin() + i);
}

// ClearAttrs method
void Record::clearAttrs()
{
    for (auto &attr : attrptr)
    {
        delete attr;
    }
    attrptr.clear();
}

// Getters and Setters
vector<Attr *> Record::getAttr() const
{
    return attrptr;
}

Attr *Record::getAttrbyindex(const int i)
{
    return attrptr[i];
}

void Record::setAttr(const int i, Attr *attr)
{
    if(i<attrptr.size())
    attrptr[i] = attr;
    else cout<<"not possible to set "<<endl;
}

bool Record::operator==(const Record &right) const
{
    // Compare each attribute in the records
    if (attrptr.size() != right.attrptr.size())
    {
        return false;
    }
    for (int i = 0; i < attrptr.size(); i++)
    {
        if (*attrptr[i] != *right.attrptr[i])
        {
            return false;
        }
    }
    return true;
}

ostream &operator<<(ostream &os, const Record &record)
{
    for (const auto &attr : record.getAttr())
    {
        os << attr << "\t";
    }
    return os;
}

void Record::printrecord(){
    for (const auto &attr : this->getAttr())
    {
        attr->printattritube();
        cout<<"\t";
    }
    // return os;

}

struct DNFformula
{
    list<list<tuple<string, char, Attr *>>> ops;
};



class Relation{
public:
    int nattrs_, nrecs_;
    vector<string> attrnames_;
    vector<int> attrinds_;
    list<Record *> recs_;
    string name_;
public:
    Relation();
    Relation(const string &name, const vector<string> &attrnames, const vector<int> &attrinds);
    int nattrs() const;
    int nrecs() const; 
    void setName(const string &name);
    string getName() const;
    void setAttrNames(const vector<string> &attrnames);
    void addAttr(const string& attrname);
    vector<string> getAttrNames() const;
    void setAttrInds(const vector<int> &attrinds);
    void addAttrInd(const int& attrindex);
    vector<int> getAttrInds() const;
    void clearRecords();
    void addRecord(Record *rec);
    void removeRecord(const int i);
    list<Record *> getRecords();
    void printrelation();
    Relation *union_(Relation *r1, Relation *r2);
    Relation *difference(Relation *r1, Relation *r2);
    Relation *cartesianProduct(Relation *r1, Relation *r2);
    Relation *projection(Relation *r1, list<string> projectattrs);
    Relation *selection(Relation *r1, DNFformula *f);
    Relation *rename_(Relation *r1, string s1, string s2);
    Relation *naturalJoin(Relation *r1, Relation *r2, list<string> joinattrs);
    friend ostream &operator<<(ostream &out, const Relation &r);
};



Relation::Relation() : nattrs_(0), nrecs_(0) {}

Relation::Relation(const string &name, const vector<string> &attrnames, const vector<int> &attrinds)
    : nattrs_(attrnames.size()), nrecs_(0), attrnames_(attrnames), attrinds_(attrinds), name_(name) {}

int Relation::nattrs() const { return nattrs_; }
int Relation::nrecs() const { return nrecs_; }

// SetName method
void Relation::setName(const string &name)
{
    name_ = name;
}

// GetName method
string Relation::getName() const
{
    return name_;
}

// SetAttrNames method
void Relation::setAttrNames(const vector<string> &attrnames)
{
    attrnames_ = attrnames;
    nattrs_ = attrnames.size();
}

void Relation::addAttr(const string& attrname)
{
    attrnames_.push_back(attrname);
    ++nattrs_;
}


// GetAttrNames method
vector<string> Relation::getAttrNames() const
{
    return attrnames_;
}

// SetAttrInds method
void Relation::setAttrInds(const vector<int> &attrinds)
{
    attrinds_ = attrinds;
}

void Relation::addAttrInd(const int& attrindex)
{
    attrinds_.push_back(attrindex);
}

// GetAttrInds method
vector<int> Relation::getAttrInds() const
{
    return attrinds_;
}

// ClearRecords method
void Relation::clearRecords()
{
    for (auto &rec : recs_)
    {
        delete rec;
    }
    recs_.clear();
    nrecs_ = 0;
}

// AddRecord method
void Relation::addRecord(Record *rec)
{
    recs_.push_back(rec);
    ++nrecs_;
}

// RemoveRecord method
void Relation::removeRecord(const int i)
{
    auto it = recs_.begin();
    advance(it, i);
    delete *it;
    recs_.erase(it);
    --nrecs_;
}

list<Record *> Relation::getRecords()
{
    return recs_;
}

void Relation::printrelation(){
    for(auto &it:attrnames_) cout<<(it)<<"\t";
    cout<<endl;
    for(auto &it:recs_) cout<<(*it)<<endl;
}

int main(){
    IntAttr *a=new IntAttr(1);
    FloatAttr *c=new FloatAttr(80.5);
    StringAttr *b=new StringAttr("harsha");

    IntAttr *a1=new IntAttr(2);
    FloatAttr *c1=new FloatAttr(20.2);
    StringAttr *b1=new StringAttr("doggy");

     vector <Attr*> atr;
    vector <Attr*> atr1;
    atr1.push_back(a1);
    atr.push_back(a);

    Record r(atr);
    Record r1(atr1);
    
    r.pushAttr(b);
    r.pushAttr(c);
    r1.pushAttr(b1);
    r1.pushAttr(c1);
   
   
    // cout<<r<<endl;
    // cout<<r1<<endl;
   

  
    
    Relation weight;
    weight.addAttr("ID");
    weight.addAttr("Name");
    weight.addAttr("Weight");
    weight.addAttr("height");

    weight.addAttrInd(0);
    weight.addAttrInd(1);
    weight.addAttrInd(2);

    weight.addRecord(&r);
    weight.addRecord(&r1);
    weight.setName("WEIGHT");

   for(auto &it: weight.recs_){
    float r;
     cout<<"enter height attr:"; cin>>r;
        it->pushAttr(new FloatAttr(r));
        // it->removeAttr(0);
   }

    cout<<"Relation: "<<weight.getName()<<endl;
    cout<<"No of attributes:"<<weight.nattrs()<<endl;
    cout<<"No of recs:"<<weight.nrecs()<<endl;

    weight.printrelation();

}
