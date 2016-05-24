/* main.cpp
 *
 * Copyright (C) 2016 Santosh Thoduka
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <roi_selection/box_selection.h>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

namespace bfs = boost::filesystem;


int main(int argc, char** argv)
{
    std::string image_directory = std::string(argv[1]);
    if (!bfs::exists(image_directory))
    {
        std::cerr << "Directory does not exist" << std::endl;
        return 1;
    }
    if (!bfs::is_directory(image_directory))
    {
        std::cerr << "Not a directory" << std::endl;
        return 1;
    }

    bfs::path sub_directory = image_directory;
    sub_directory /= bfs::path("cropped");
    bfs::create_directory(sub_directory);


    std::set<std::string> sorted_names;
    bfs::directory_iterator end;
    for (bfs::directory_iterator iter(image_directory); iter != end; ++iter)
    {
        if (!bfs::is_directory(*iter))
        {
            sorted_names.insert(iter->path().filename().string());
        }
    }

    BoxSelection bs;
    std::set<std::string>::iterator iter;
    for (iter = sorted_names.begin(); iter != sorted_names.end(); ++iter)
    {
        bfs::path p = image_directory / bfs::path(*iter);
        if (!bfs::is_directory(*iter))
        {
            cv::Mat frame = cv::imread(p.string(), CV_LOAD_IMAGE_COLOR);
            if (!frame.data)
            {
                std::cerr << p.string() << " is not an image" << std::endl;
                continue;
            }
            std::cout << "loading file: " << *iter << std::endl;
            cv::Point top_left;
            cv::Point bottom_right;
            bs.selectBox(frame, top_left, bottom_right);
            int width = bottom_right.x - top_left.x;
            int height = bottom_right.y - top_left.y;
            cv::Mat cropped_image = frame(cv::Rect(top_left.x, top_left.y, width, height));
            std::string new_file_name = (sub_directory / bfs::path(*iter)).string();
            cv::imwrite(new_file_name, cropped_image);
            std::cout << "saved file: " << new_file_name << std::endl;
        }
    }

}
