/* box_selection.h
 *
 * Copyright (C) 2014 Santosh Thoduka
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef BOX_SELECTION_H_
#define BOX_SELECTION_H_

#include <opencv2/opencv.hpp>

class BoxSelection
{
    public:
        BoxSelection();
        virtual ~BoxSelection();

        void selectBox(const cv::Mat &frame, cv::Point &top_left, cv::Point &bottom_right);


        static void mouseCallback(int event, int x, int y, int flags, void *param);
        void doMouseCallback(int event, int x, int y, int flags);

    private:
        cv::Mat frame_;
        bool is_satisfied_;
        bool received_top_left_;
        bool received_bottom_right_;
        cv::Point top_left_;
        cv::Point bottom_right_;
};

#endif
