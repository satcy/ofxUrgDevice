#include <memory>
#include <vector>
#include "UrgData.h"

using std::vector;

class ofxUrgDevice
{
public:
    static const string DEFAULT_HOST;
    static const int DEFAULT_PORT = 10940;
    ofxUrgDevice();
    ~ofxUrgDevice();
    
    void setup();
    void setup(const std::string& device);
    void setup(const std::string& host, int port);
    void update();
    void draw(float x, float y) const;
    void drawCoordinate(float x, float y) const;
    void connect();
    void disconnect();
    
    void setSensorAngle(float degree);
    
    std::vector<std::string> getDevices() const;
    ofxUrg::UrgData getData() const;
    long minDistance() const;
    long maxDistance() const;
    int maxScanIndex() const;
    double maxScanAngle() const;
    double index2rad(const int index) const;
    
private:
    struct Impl;
//    std::auto_ptr<Impl> pImpl;
    Impl* pImpl;
    
};

const ofxUrgDevice::DEFAULT_HOST = "192.168.0.10";
