#include "../include/TopPtSF.h"

TopPtSF::TopPtSF(std::string year, std::vector<int> idxToCheck) :
//DP EDIT all the data sets were being referenced as 'data' but it should be 'Data' - edited
{};

std::vector<int> TopPtSF::eval(RVec<float> Dijet_particleNet_TvsQCD, RVec<float> Dijet_pt) {
    float eventWeight;
    eventWeight=1.0;
//    std::cout << 'at A' <<  eventWeight[0] << std::endl;
    if (_idxToCheck.empty()) {
        _idxToCheck.resize(FatJet_eta.size());
        std::iota(_idxToCheck.begin(), _idxToCheck.end(), 0);
    }
    for (size_t i = 0; i < _idxToCheck.size(); i++) {
        int idx = _idxToCheck[i];
//        std::cout << 'at B' << eventWeight[0] << eventWeight[1] << std::endl;
    }
    eventWeight=1.0;
    return {eventWeight};
}
