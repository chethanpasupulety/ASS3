#include <bits/stdc++.h>
using namespace std;
// #include"rdb.h"

class Attr
{protected: string dtype;
public:
    // Base class for attributes
     Attr(string s):dtype(s){}
     string getvalue()const{return dtype;}
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
private:
    int value_;
public:
    IntAttr(int value,string d="int") : value_(value), Attr(d) {}

    void printattritube(){cout<<value_;}

    int getvalue()const {return(value_);}

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
private:
    string value_;
public:
    StringAttr(string value,string d="string") : value_(value),Attr(d) {}
    
    void printattritube(){cout<<value_;}

    string getvalue()const {return value_;}

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
private:
    float value_;
public:
    FloatAttr(float value,string d="float") : value_(value),Attr(d) {}

    void printattritube(){cout<<value_;}

    float getvalue() const{return value_;}

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
        os << a.getvalue();
        return os;
    }

       ostream& operator<< (ostream& os,const StringAttr &a)  {
        os <<a.getvalue();
        return os;
    }

       ostream& operator<< (ostream& os,const FloatAttr &a)  {
        os <<a.getvalue();
        return os;
    }


ostream& operator<<(ostream &os, Attr* attr){
   

         if(attr->dtype=="int") {IntAttr* p1=dynamic_cast<IntAttr*>(attr);os<<p1->getvalue();}
    else if(attr->dtype=="float"){ FloatAttr* p1=dynamic_cast<FloatAttr*>(attr);os<<p1->getvalue();}
    else { StringAttr* p1=dynamic_cast <StringAttr*> (attr);os<<p1->getvalue();}
    return os;

}


class Record{
private:
    vector<Attr *> attrptr;
public:
    Record();
    Record(const vector<Attr*>& attrs);
    int size() const;
    void pushAttr(Attr *attr);
    void removeAttr(const int i);
    void clearAttrs();
    vector<Attr*> getAttr() const;
    Attr* getAttrbyindex(const int i);
    void setAttr(const int i, Attr *attr);
    bool operator==(const Record &right) const;
     friend ostream& operator<<(ostream &os, const Record& record) ;
    void printrecord();
    ~Record();
    friend class Relation;
};


// Record::Record(int n){
    
// }

// Constructor

Record::Record(){}


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
private:
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
    friend Relation *union_(Relation *r1, Relation *r2);
    friend Relation *difference(Relation *r1, Relation *r2);
    friend Relation *cartesianProduct(Relation *r1, Relation *r2);
    friend Relation *projection(Relation *r1, list<string> &projectattrs);
    // Relation *selection(Relation *r1, DNFformula *f);
    friend Relation *rename_(Relation *r1, string s1, string s2);
    // Relation *naturalJoin(Relation *r1, Relation *r2, list<string> joinattrs);
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

// 1. Union: All records of both R1 and R2.
Relation* union_(Relation *R1, Relation *R2)
{ // Check if the schemas are the same
    if (R1->getAttrNames() != R2->getAttrNames())
    {
        cerr << "Error: Cannot perform union operation on relations with different schemas\n";
        return nullptr;
    }

    Relation *result = new Relation();
    result->setName("Union ("+R1->getName() + " , "+ R2->getName()+")"); // Use the name of the first relation

    // Add attribute names and indices
    result->setAttrNames(R1->getAttrNames());
    result->setAttrInds(R1->getAttrInds());

    // Add records from R1
    for (Record *rec : R1->getRecords())
    {
        result->addRecord(new Record(*rec));
    }

    // Add records from R2 that are not already in R1
    for (Record *rec : R2->getRecords())
    {
        bool found = false;
        for (Record *r : result->getRecords())
        {
            if (*r == *rec)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            result->addRecord(new Record(*rec));
        }
    }
    return result;
}

// 2. Difference: Records in R1 but not in R2.
Relation* difference(Relation *R1, Relation *R2)
{ // Check if R1 and R2 have the same schema
    if (R1->getAttrNames() != R2->getAttrNames() || R1->getAttrInds() != R2->getAttrInds())
    {
        cout << "Error: schemas of R1 and R2 are not the same." << endl;
        return nullptr;
    }

    // Create a new relation with the same schema as R1 and R2
    vector<string> attrnames = R1->getAttrNames();
    vector<int> attrinds = R1->getAttrInds();
    string name = "Difference ("+R1->getName() + " , "+ R2->getName()+")";
    Relation *result = new Relation(name, attrnames, attrinds);

    // Add records from R1 that are not in R2
    for (Record *rec : R1->getRecords())
    {
        bool found = false;
        for (Record *r : R2->getRecords())
        {
            if (*r == *rec)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            result->addRecord(new Record(*rec));
        }
    }

    return result;
}

Relation* cartesianProduct(Relation *r1, Relation *r2)
{
    // Create a new relation
    Relation *res = new Relation();

    // Set the name of the new relation to the concatenation of the names of r1 and r2
    res->setName("CartesianProduct ("+r1->getName() + " , "+ r2->getName()+")");

    // Set the attribute names and indices of the new relation
    vector<string> attrnames;
    vector<int> attrinds;
    for (int i = 0; i < r1->nattrs(); i++)
    {
        attrnames.push_back(r1->getAttrNames()[i]);
        attrinds.push_back(i);
    }
    for (int i = 0; i < r2->nattrs(); i++)
    {
        attrnames.push_back(r2->getAttrNames()[i]);
        attrinds.push_back(i + r1->nattrs());
    }
    res->setAttrNames(attrnames);
    res->setAttrInds(attrinds);

    // Add the cartesian product of the records of r1 and r2 to the new relation
    for (auto r1rec : r1->getRecords())
    {
        for (auto r2rec : r2->getRecords())
        {
            vector<Attr *> attrs;
            for (auto attr : r1rec->getAttr())
            {
                attrs.push_back(attr);
            }
            for (auto attr : r2rec->getAttr())
            {
                attrs.push_back(attr);
            }
            Record *rec = new Record(attrs);
            res->addRecord(rec);
        }
    }

    return res;
}

// 4. Projection: New relation with a subset of columns.
Relation* projection(Relation *r1, list<string> &projectattrs)
{
        int i;
    vector<int> projIndices;
    for (auto attrName : projectattrs)
    {
        i=0;
        // auto it = find(r1->getAttrNames().begin(), r1->getAttrNames().end(), attrName);
        for(auto it:r1->getAttrNames()){
            if(attrName==r1->getAttrNames()[i]) break;
            else i++;
        }
        if(i==r1->getAttrNames().size()) {
             cerr << "Error: Attribute " << attrName << " not found in relation.\n";
            return nullptr;

        }
       int index=i;
        // cout<<*it<<endl;
        // if (it == r1->getAttrNames().end())
        // {
        //     cerr << "Error: Attribute " << attrName << " not found in relation.\n";
        //     return nullptr;
        // }
        // int index = distance((r1->getAttrNames()).begin(), it);
        // cout<<"index found"<<index<<endl;
        projIndices.push_back(index);
    }

    vector<string> projAttrNames;
    for (auto index : projIndices)
    {
        cout<<(r1->getAttrNames())[index]<<endl;
        projAttrNames.push_back((r1->getAttrNames())[index]);
    }

    vector<int> projAttrInds;
    for (auto index : projIndices)
    {
        projAttrInds.push_back(r1->getAttrInds()[index]);
    }

    Relation *projRelation = new Relation("Projection("+r1->getName()+")", projAttrNames, projAttrInds);

     vector<Attr *> projAttrs;
    for (auto rec : r1->getRecords())
    {
        // vector<Attr *> projAttrs;
        for (auto index : projIndices)
        {
            projAttrs.push_back(rec->getAttrbyindex(index));
        }
        projRelation->addRecord(new Record(projAttrs));
        projAttrs.clear();
    }

    return projRelation;
}

// 6. Rename: rename an attribute in schema
Relation* rename_(Relation *r1, string s1, string s2)
{
    vector<string> attrnames = r1->getAttrNames();
    for (int i = 0; i < attrnames.size(); i++)
    {
        if (attrnames[i] == s1)
        {
            attrnames[i] = s2;
        }
    }
    r1->setAttrNames(attrnames);
    return r1;
}

int main(){
    IntAttr *a=new IntAttr(1);
    FloatAttr *c=new FloatAttr(80.5);
    StringAttr *b=new StringAttr("harsha");

    IntAttr *a1=new IntAttr(2);
    FloatAttr *c1=new FloatAttr(20.2);
    StringAttr *b1=new StringAttr("doggy");


       IntAttr *a2=new IntAttr(3);
    FloatAttr *c2=new FloatAttr(80.5);
    StringAttr *b2=new StringAttr("harsha");

    IntAttr *a3=new IntAttr(4);
    FloatAttr *c3=new FloatAttr(50);
    StringAttr *b3=new StringAttr("kurma");


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
   
    Relation weight;
    weight.addAttr("ID");
    weight.addAttr("Name");
    weight.addAttr("Weight");
    // weight.addAttr("height");

    weight.addAttrInd(0);
    weight.addAttrInd(1);
    weight.addAttrInd(2);

    weight.addRecord(&r);
    weight.addRecord(&r1);
    weight.setName("WEIGHT1");

//    for(auto &it: weight.recs_){
//     float r;
//      cout<<"enter height attr:"; cin>>r;
//         it->pushAttr(new FloatAttr(r));
//         // it->removeAttr(0);
//    }




 atr1.clear();
    atr.clear();

atr1.push_back(a2);
atr.push_back(a3);

Record *l1=new Record(atr1);

l1->pushAttr(b2);
l1->pushAttr(c2);


Record *l2=new Record(atr);
l2->pushAttr(b3);
l2->pushAttr(c3);

Relation *R=new Relation();

    R->setAttrNames(weight.getAttrNames());
    R->setAttrInds(weight.getAttrInds());
    // R->attrnames_.pop_back();
    R->addRecord(l1);
    R->addRecord(l2);
    R->setName("WEIGHT2");

    //printing 1st relation
     cout<<"Relation: "<<weight.getName()<<endl;
    cout<<"No of attributes:"<<weight.nattrs()<<endl;
    cout<<"No of recs:"<<weight.nrecs()<<endl;

    weight.printrelation();

        cout<<endl<<endl;

    
    //printing 2nd relation
   cout<<"Relation: "<<R->getName()<<endl;
    cout<<"No of attributes:"<<R->nattrs()<<endl;
    cout<<"No of recs:"<<R->nrecs()<<endl;

    R->printrelation();
  cout<<endl<<endl;
    // Relation *R2=cartesianProduct(&weight,R);
    // cout<<"Relation: "<<R2->getName()<<endl;
    // cout<<"No of attributes:"<<R2->nattrs()<<endl;
    // cout<<"No of recs:"<<R2->nrecs()<<endl;

    // R2->printrelation();

    // for(auto &it:R2->getAttrInds()){
    //     cout<<it;
    // }


//     list <string> L;
//     L.push_back("Name");
//     L.push_back("weight");
//     // cout<<"\ndog\n";
//      R2=projection(R2,L);
//      cout<<"Relation: "<<R2->getName()<<endl;
//     cout<<"No of attributes:"<<R2->nattrs()<<endl;
//     cout<<"No of recs:"<<R2->nrecs()<<endl;

//     R2->printrelation();
//   cout<<endl<<endl;

}
