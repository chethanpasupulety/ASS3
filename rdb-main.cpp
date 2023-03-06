#include <bits/stdc++.h>
#include "rdb.h"
using namespace std;



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
    Relation *R2=cartesianProduct(&weight,R);
    cout<<"Relation: "<<R2->getName()<<endl;
    cout<<"No of attributes:"<<R2->nattrs()<<endl;
    cout<<"No of recs:"<<R2->nrecs()<<endl;

    R2->printrelation();

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