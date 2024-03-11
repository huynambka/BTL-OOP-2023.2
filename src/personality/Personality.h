#ifndef PERSONALITY_H
#define PERSONALITY_H

#include "lib/nlohmann/json.hpp"

using json = nlohmann::json;
class Personality
{
protected:
    double lamda;
    double positiveEmotionThreshold;
    double negativeEmotionThreshold;

public:
    Personality();
    Personality(double lamda, double ne, double pos);
    ~Personality();
    double getLamda() const { return lamda; }
    double getPositiveEmotionThreshold() const { return positiveEmotionThreshold; }
    double getNegativeEmotionThreshold() const { return negativeEmotionThreshold; }
    void setLamda(double lamda) { this->lamda = lamda; }
    void setPositiveEmotionThreshold(double positiveEmotionThreshold) { this->positiveEmotionThreshold = positiveEmotionThreshold; }
    void setNegativeEmotionThreshold(double negativeEmotionThreshold) { this->negativeEmotionThreshold = negativeEmotionThreshold; }
    json toJson();
};
#endif