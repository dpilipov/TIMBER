#include "../include/TopSF.h"

TopSF::TopSF(std::vector<int> idxToCheck) :
//DP EDIT all the data sets were being referenced as 'data' but it should be 'Data' - edited
//    _isAffectedData((InString("Data",setname) || InString("data",setname)) && (InString("C",setname) || InString("D",setname) || InString("B",setname))),
//    _isDataB(InString("DataB",setname)), _idxToCheck(idxToCheck), _setname(setname)
//{};

std::vector<float> TopSF::eval(std::vector<float> Dijet_particleNet_TvsQCD,std::vector<float> Dijet_pt ,std::vector<float> JetSF)
/*, float genWeight) {
*/
    float eventW;
    eventW=1.0;
    if (_idxToCheck.empty()) {
        _idxToCheck.resize(JetSF.size());
        std::iota(_idxToCheck.begin(), _idxToCheck.end(), 0);
    }
    genWeight=SF[0]*genWeight;
    return {genWeight};
}
