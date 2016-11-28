#include <iostream>

#include <cv.h>
#include <opencv.hpp>

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace cv;

/**
 * actually used for change image format type / extension
 * @param pic_read_path
 * @param pic_write_path
 * @return
 */
bool ChangeFormat(const string &pic_read_path, const string &pic_write_path) {
    Mat tOriPic = imread(pic_read_path);

    if (tOriPic.empty())
        return false;

    return imwrite(pic_write_path, tOriPic);
}

/**
 * change all files which ext == pic_curr_ext into files with pic_future_ext, in fold find_pics_dir
 * @param find_pics_dir
 * @param pic_curr_ext
 * @param pic_future_ext
 */
void GetAllTypeFileInPathOperated(const string &find_pics_dir, const string &pic_curr_ext, const string &pic_future_ext) {
    boost::filesystem::path tCurrPath(find_pics_dir);
    if (!boost::filesystem::exists(tCurrPath))
        return;

    boost::filesystem::directory_iterator end_dir_iter;
    for (boost::filesystem::directory_iterator dir_iter(tCurrPath); dir_iter != end_dir_iter; ++dir_iter) {
        if (boost::filesystem::is_regular_file(*dir_iter) && dir_iter->path().extension() == pic_curr_ext) {
            // get the template image
            string pic_read_path = dir_iter->path().string();

            boost::filesystem::path curr_path = dir_iter->path();
            string pic_write_path = curr_path.replace_extension(pic_future_ext).string();

            if (ChangeFormat(pic_read_path, pic_write_path))
                printf("File:%s is converted into NEW file:%s\n", pic_read_path.c_str(), pic_write_path.c_str());
        }
    }
    return;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s pic_folder ext_curr_file ext_need_format\n", argv[0]);
        return 1;
    }

    string strPicDir = argv[1];
    string pic_curr_ext = argv[2];
    string pic_future_ext = argv[3];

    GetAllTypeFileInPathOperated(strPicDir, pic_curr_ext, pic_future_ext);

    return 0;
}