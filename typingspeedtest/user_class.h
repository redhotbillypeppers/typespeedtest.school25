#include <vector>
#include <string>
#include <fstream>

//user class made for individual statistic tracking
class user {
  public:
  //user name
  std::string name;

  //test average wpm variables
  //0 = easy 1= medium
  //2 = hard 3 = test 4 = total average
  float averageWPM[5] = {0.0, 0.0, 0.0, 0.0, 0.0};

  //array of 4 vectors that store the game results
  //0=easy 1=medium 2=hard 3=test emh = easy medium hard
  std::vector<float> WPMGames[4];



  //simple constructor that accepts the name of the user
  user (std::string n) {
    name = n;
  }

  //method calculates total statistics
  void wpmAverageCalc0123(){
    float allTestWPMSum = 0.00;
    float allTestCount = 0.00;
    for(int j = 0; j<4; j++){
      float singleTestSum = 0.00;
      for(float i : WPMGames[j]){
        singleTestSum += i;
      }
     averageWPM[j] = (singleTestSum / std::size(WPMGames[j]));
     allTestCount += WPMGames[j].size();
     allTestWPMSum += singleTestSum;
    }
  averageWPM[4] = allTestWPMSum/allTestCount;
  }
};
