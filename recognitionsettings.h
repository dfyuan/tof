#ifndef RECOGNITIONSETTINGS_H
#define RECOGNITIONSETTINGS_H

#include <vector>
#include <memory>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class RecognitionSettings
{
public:
    RecognitionSettings();
    ~RecognitionSettings();


    inline void setBedRecThresholdScale(int scale) {
        this->bed_rec_threshold_scale = scale;
    }

    inline int getBedRecThresholdScale() const {
        return bed_rec_threshold_scale;
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

    inline int getBedHistBins() const {
        return bed_hist_bins;
    }

    inline void setBedHistBins(int bins) {
        this->bed_hist_bins = bins;
    }

    inline void setFloorHistBins(int bins) {
        this->floor_hist_bins = bins;
    }

    inline int getFloorHistBins() const {
        return floor_hist_bins;
    }

    inline void setBedHistRanges(std::shared_ptr<float> &ranges) {
        this->bed_hist_ranges = ranges;
    }

    inline std::shared_ptr<float> getBedHistRanges() const {
        return bed_hist_ranges;
    }

    inline void setFloorHistRanges(std::shared_ptr<float> &ranges) {
        this->floor_hist_ranges = ranges;
    }

    inline std::shared_ptr<float> getFloorHistRanges() const {
        return floor_hist_ranges;
    }

    inline void setConvertScale(double scale) {
        this->convert_scale = scale;
    }

    inline double getConvertScale() const {
        return convert_scale;
    }

    inline std::array<cv::Point2f, 4> getBedCorners() const {
        return bed_corners;
    }

    void  bedRecognition(cv::Mat img);


private:
    int bed_rec_threshold_scale;
    int med_blur_scale;
    int hum_cont_threshold_scale;
    int width;
    int height;
    int bed_hist_bins;
    int floor_hist_bins;
    std::shared_ptr<float> bed_hist_ranges;
    std::shared_ptr<float> floor_hist_ranges;
    std::array<cv::Point2f, 4> bed_corners;

    double min_human_area;
    double max_noise_area;
    double convert_scale;

};

#endif // RECOGNITIONSETTINGS_H
