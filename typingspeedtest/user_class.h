#include <vector>
#include <string>

#ifndef USER_CLASS_H
#define USER_CLASS_H

#endif //USER_CLASS_H
//user class made for individual statistic tracking
class user {
  public:
  //user name
  std::string name;

  //array of 4 vectors that store the game results
  std::vector<float> WPMGames[4];

  //test average wpm variables
  //0 = easy 1= medium
  //2 = hard 3 = test 4 = total average
  float averageWPM[5];

//0=easy 1=medium 2=hard 3=test emh = easy medium hard

  user (std::string n) {
    name = n;
    for (int i = 0; i < 4; i++) {
      WPMGames[i].resize(4);
      for (int j = 0; j < 4; j++) {
        WPMGames[i][j] = 0;
      }
    }

  }
  void wpmAverageCalc0123(){
    float allTestWPMSum = 0.00;
    float allTestCount = 0.00;
    for(int j = 0; j<4; j++){
      float singleTestSum = 0.00;
      for(float i : WPMGames[j]){
        singleTestSum += i;
      }
      /*^^ above is an "improved" range based for loop?
       *below is hand made while above is IDE generated
       *vvv
      for(int i = 0; i < WPMGames[j].size(); i++){
        singleTestSum += WPMGames[j][i];
      }
      */
     averageWPM[j] = (singleTestSum / std::size(WPMGames[j]));
     allTestCount += WPMGames[j].size();
     allTestWPMSum += singleTestSum;
    }
  averageWPM[4] = allTestWPMSum/allTestCount;
  }
};