#include "../include/TopPt_SF.h"

TopPt_SF::TopPt_SF(int year);

float TopPt_SF::eval(float TvsQCD, float pt){

/*float TopPt_SF::eval(RVec<float> Dijet_particleNet_TvsQCD, RVec<float> Dijet_pt){
*/
    float SF2016APV[3][4] = {{1.23,1.07,1.06,1.10},{1.36,1.20,1.12,1.39},{1.09,1.02,1.01,1.00}};
    float SF2016[3][4]    = {{1.07,0.97,1.03,1.34},{1.17,1.02,1.08,1.58},{0.97,0.92,0.99,1.07}};
    float SF2017[3][4]    = {{1.11,1.01,1.05,1.00},{1.19,1.05,1.09,1.05},{1.03,0.97,1.01,0.95}};
    float SF2018[3][4]    = {{1.19,0.98,0.96,0.97},{1.31,1.02,0.99,1.02},{1.07,0.94,0.93,0.92}};
    std::string syear="2016";
    int ptCat=-1;
    int _var=0;
    int idx=0;
    int wpCat=0;
    float taggerWP=10.0;
    float SF=1.0;
    if (year == 16) {
       syear="2016";
       taggerWP=0.73;
    } elif (year == 17) {
       syear = "2017";
       taggerWP=0.8;
    } elif (year == 18) {
       syear = "2018";
       taggerWP=0.8;
    } else {
       syear = "2016APV";
       taggerWP=0.74;
    }
    if (TvsQCD > taggerWP) {
       wpCat = 1;
    }
    if (wpCat > 0) {
       if ((pt >= 300) && (pt < 400))       { ptCat = 0; }
       else if ((pt >= 400) && (pt < 480))  { ptCat = 1; }
       else if ((pt >= 480) && (pt < 600))  { ptCat = 2; }
       else if ((pt >= 600) && (pt < 1200)) { ptCat = 3; }
       else { return 1.0; }
       if (ptCat > -1) {
            if (syear=="2016APV") { SF = SF2016APV[_var][ptCat]; }
            else if (syear=="2016") { SF = SF2016[_var][ptCat]; }
            else if (syear=="2017") { SF = SF2017[_var][ptCat]; }
            else { SF = SF2018[_var][ptCat]; }
       }
    }
    return {SF};
}
