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

  //array of 3 vectors that store the game results
  std::vector<float> WPMGames[4];

  //test average wpm variables
  //0 = easy 1= medium
  //2 = hard 3 = test 4 = total average
  float averageWPM[5];

//0=easy 1=medium 2=hard 3=test emh = easy medium hard

  void wpmAverageCalc0123(){
    float alltestsum = 0.00;
    float alltestcount = 0.00;
    for(int j = 0; j<4; j++){
      float singletestsum = 0.00;
      for(int i = 0; i < WPMGames[j].size(); i++){
        singletestsum += WPMGames[j][i];
      }
     averageWPM[j] = (singletestsum / WPMGames.size());
     alltestcount += WPMGames[j].size();
     alltestsum += singletestsum;
    }
  averageWPM[5] = alltestcount/alltestsum;
  }
}