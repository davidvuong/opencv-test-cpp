#include <iostream>
#include <opencv2/opencv.hpp>
#include "config.hpp"

using namespace cv;

int main() {
  std::cout << APP_VERSION_MAJOR << "." << APP_VERSION_MINOR << "." << APP_VERSION_PATCH << std::endl;

  // VideoCapture::VideoCapture(int device)
  // There are other constructors to VideoCapture (0 - webcam).
  //
  // @see: https://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html
  VideoCapture videoCapture(0);

  if (!videoCapture.isOpened()) {
    std::cout << "Video capture is not opened. prematurely exiting..." << std::endl;
    return -1;
  }

  // Mat = Matrix (n-dimensional array storing the raw values in a frame).
  Mat frame;
  bool isSuccessfulRead = videoCapture.read(frame);
  if (!isSuccessfulRead) {
    std::cout << "Could not read frame from video source. prematurely exiting..." << std::endl;
    return isSuccessfulRead;
  }

  std::vector<int> compressionParams;
  compressionParams.push_back(CV_IMWRITE_JPEG_QUALITY);
  compressionParams.push_back(80);

  namedWindow("test", CV_WINDOW_AUTOSIZE );
  imshow("test", frame);
  waitKey(10000);

  std::cout << "Successfully completed video capture. Exiting." << std::endl;

  // Closes video file or capturing device.
  videoCapture.release();
  return 0;
}
