#include "../include/HEM_drop.h"

HEM_drop::HEM_drop(std::string setname, std::vector<int> idxToCheck) :
//DP EDIT all the data sets were being referenced as 'data' but it should be 'Data' - edited
    _isAffectedData((InString("Data",setname) || InString("data",setname)) && (InString("C",setname) || InString("D",setname) || InString("B",setname))),
    _isDataB(InString("DataB",setname)), _idxToCheck(idxToCheck), _setname(setname)
{};

std::vector<int> HEM_drop::eval(RVec<float> FatJet_eta, RVec<float> FatJet_phi, int run) {
    int eventWeight;
    eventWeight=1;
//    std::cout << 'at A' <<  eventWeight[0] << std::endl;
    if (_idxToCheck.empty()) {
        _idxToCheck.resize(FatJet_eta.size());
        std::iota(_idxToCheck.begin(), _idxToCheck.end(), 0);
    }
    for (size_t i = 0; i < _idxToCheck.size(); i++) {
        int idx = _idxToCheck[i];
//DP EDIT eta was > -2.5 and changed to -3.2 as per latest recommendations
        if ((FatJet_eta[idx] < -1.3) && (FatJet_eta[idx] > -3.2) && (FatJet_phi[idx] < -0.87) && (FatJet_phi[idx] > -1.57)){
            if (_isAffectedData) {
                if (run>319076)) {
                    eventWeight = 0; // If affected 2018B, C, or D
                    break;
                }
            } else if (!InString("data",_setname)){
//DP EDIT change this to random weight setting... in place of eventWeight = 0.35
                float rand = _rand->Uniform(1.0);
                if (rand < 0.65) {
                   eventWeight = 0; // If affected MC
                break;
            }
        }
//        std::cout << 'at B' << eventWeight[0] << eventWeight[1] << std::endl;
    }
    return {eventWeight};
}
