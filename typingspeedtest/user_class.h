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
  //2 = hard 3 = analysis 4 = total average
  float averageWPM[5] = {0.0, 0.0, 0.0, 0.0, 0.0};

  //array of 4 vectors that store the game results
  //0=easy 1=medium 2=hard 3=analysis
  std::vector<float> WPMGames[4];



  //simple constructor that accepts the name of the user
  user (std::string n) {
    name = n;
  }

  //method calculates total statistics
  void wpmAverageCalc0123(){
    float allTestWPMSum = 0.00; //sum of wpm for every test taken (numerator of average formula)
    float allTestCount = 0.00; //the amount of tests taken in total (denominator of average formula)
    for(int j = 0; j<4; j++){ // this loop iterates on the 4 vectors holding their respective test stats
      float singleTestSum = 0.00; //initialize the sum for a singular test for a singular user
      for(float i : WPMGames[j]){ //sum up the wpm for a singular test for a singular user
        singleTestSum += i;
      }
     averageWPM[j] = (singleTestSum / std::size(WPMGames[j])); //gets the average wpm for a single test for a single user
     allTestCount += WPMGames[j].size(); //sums the denominator for the average
     allTestWPMSum += singleTestSum; // sums the numerator for the average
    }
  averageWPM[4] = allTestWPMSum/allTestCount; // gets the total average wpm for all games of a single user
  }
};
