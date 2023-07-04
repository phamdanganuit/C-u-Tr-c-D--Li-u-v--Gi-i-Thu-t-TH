#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
    VideoCapture cap(0); // Sử dụng camera laptop (ID=0)

    if (!cap.isOpened()) // Kiểm tra xem camera có khả dụng hay không
    {
        std::cerr << "Không thể mở camera!" << std::endl;
        return -1;
    }

    while (true) // Vòng lặp để xử lý các khung hình từ camera
    {
        Mat frame;
        cap >> frame; // Lấy khung hình từ camera

        if (frame.empty()) // Kiểm tra xem khung hình có hợp lệ hay không
        {
            std::cerr << "Khung hình trống!" << std::endl;
            break;
        }

        // Xử lý khung hình để đếm số ngón tay hiện lên ở đây

        imshow("Frame", frame); // Hiển thị khung hình

        if (waitKey(30) == 'q') // Đợi 30ms và kiểm tra xem có phím 'q' được nhấn hay không
        {
            break;
        }
    }

    return 0;
}
