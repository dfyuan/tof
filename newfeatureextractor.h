#ifndef NEWFEATUREEXTRACTOR_H
#define NEWFEATUREEXTRACTOR_H

#include <FeatureExtractor.h>
#include <array>
#include <ssuexception.h>
#include <log.h>
#include <math.h>
#include "posefeatures.h"
#include <memory.h>

#define _USE_MATH_DEFINES

const double MAX_COLOR = 655535;
const double COLOR_SCALE = 0.00390625;
#define  BED_INTENSITY_SIZE  5
#define FLOOR_INTENSITY_SIZE 4

class FeatureExtractorException : public SsuException
{
public:
    FeatureExtractorException(const std::string& reason):SsuException(reason){}
};

class NewFeatureExtractor : public FeatureExtractor
{
public:
    NewFeatureExtractor();
    virtual ~NewFeatureExtractor();

    virtual shared_ptr<PoseFeatures> extractFeatures(cv::Mat frame);
    cv::Mat imageTransformation(cv::Mat img, double depthCur, double offsetCur, double depthNew, double offsetNew);

    inline void setBedRecThresholdScale(int scale) {
        this->bed_rec_threshold_scale = scale;
    }

    inline int getBedRecThresholdScale() const {
        return bed_rec_threshold_scale;
    }

    inline void setEmptyImage(cv::Mat &empty) {
        this->empty_image = empty;
    }

    inline cv::Mat getEmptyImage() const {
        return empty_image;
    }

    inline void setMedianBlurScale(int scale) {
        this->med_blur_scale = scale;
    }

    inline int getMedianBlurScale() const {
        return med_blur_scale;
    }

    inline void setHumContThresholdScale(int scale) {
        this->hum_cont_threshold_scale = scale;
    }

    inline int getHumContThresholdScale() const {
        return hum_cont_threshold_scale;
    }

    inline void setMinHumanArea(double area) {
        this->min_human_area = area;
    }

    inline double getMinHumanArea() const {
        return min_human_area;
    }

    inline void setWidth(int width)
    {
        this->width = width;
    }

    inline int getWidth() const {
        return width;
    }

    inline void setHeight(int height) {
        this->height = height;
    }

    inline int getHeight() const {
        return height;
    }

    inline void setMaxNoiseArea(double area) {
        this->max_noise_area = area;
    }

    inline double getMaxNoiseArea() const {
        return max_noise_area;
    }

    inline int getHistBins() const {
        return hist_bins;
    }

    inline void setHistBins(int bins) {
        this->hist_bins = bins;
    }

    inline void setBedHistRanges(shared_ptr<float> &ranges) {
        this->bed_hist_ranges = ranges;
    }

    inline shared_ptr<float> getBedHistRanges() const {
        return bed_hist_ranges;
    }

    inline void setFloorHistRanges(shared_ptr<float> &ranges) {
        this->floor_hist_ranges = ranges;
    }

    inline shared_ptr<float> getFloorHistRanges() const {
        return floor_hist_ranges;
    }

    inline void setFrameAngle(double angle) {
        this->frame_angle = angle;
    }

    inline double getFrameAngle() const {
        return frame_angle;
    }


    void  bedRecognition(cv::Mat img);
    cv::Mat changeIntensity(cv::Mat img, double degree);
    std::vector<std::vector<cv::Point>> getHumanContours(cv::Mat img);
    bool is_in_bed(double x, double y);
    bool is_in_bed(cv::Point2f point);
    bool is_empty(cv::Mat img);
    bool is_human_in_bed(cv::Mat img);
    std::array<double, 2> getHumanArea(cv::Mat img);
    double getHumanLength(cv::Mat img);
    std::vector<cv::Point> getHumanMaxContour(std::vector<std::vector<cv::Point>> &&contours);
    std::vector<float> getBedIntensityHistogram(cv::Mat img);
    std::vector<float> getFLoorIntensityHistogram(cv::Mat img);


private:
    int bed_rec_threshold_scale = 60;
    int med_blur_scale = 5;
    int hum_cont_threshold_scale = 3;
    int width = 640;
    int height = 480;
    int hist_bins = 4;
    shared_ptr<float> bed_hist_ranges;
    shared_ptr<float> floor_hist_ranges;
    double min_human_area;
    double max_noise_area;
    double frame_angle;
    std::array<cv::Point2f, 4> bed_corners;
    cv::Mat empty_image;

};

#endif // NEWFEATUREEXTRACTOR_H