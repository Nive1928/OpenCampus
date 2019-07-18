import cv2
import numpy as np
from PIL import Image

Picture = "cutjotaro.png"

def resize_image(image, height, width):

        org_height, org_width = image.shape[:2]

        if float(height)/org_height > float(width)/org_width:
                ratio = float(height)/org_height
        else:
                ratio = float(width)/org_width

        resized = cv2.resize(image,(int(org_height*ratio),int(org_width*ratio)))

        return resized

def overlayOnPart(src_image, overlay_image, posX, posY):
        ol_height, ol_width = overlay_image.shape[:2]
        src_image_RGBA = cv2.cvtColor(src_image, cv2.COLOR_BGR2RGB)
        overlay_image_RGBA = cv2.cvtColor(overlay_image, cv2.COLOR_BGRA2RGBA)

        src_image_PIL=Image.fromarray(src_image_RGBA)
        overlay_image_PIL=Image.fromarray(overlay_image_RGBA)

        src_image_PIL = src_image_PIL.convert('RGBA')
        overlay_image_PIL = overlay_image_PIL.convert('RGBA')

        tmp = Image.new('RGBA', src_image_PIL.size, (255, 255, 255, 0))

        tmp.paste(overlay_image_PIL, (posX, posY), overlay_image_PIL)

        result = Image.alpha_composite(src_image_PIL, tmp)

        return cv2.cvtColor(np.asarray(result), cv2.COLOR_RGBA2BGR)

try:
        capture = cv2.VideoCapture(0)
        cascade = cv2.CascadeClassifier('/home/ykhiguma/opencv/sources/data/haarcascades_cuda/haarcascade_frontalface_alt.xml')
        img = cv2.imread(Picture)
        
        while(True):
                ret, frame = capture.read()
                if ret == False:
                        print("Can't get video from Camera")
                        continue
                facerect = cascade.detectMultiScale(frame)
                                
                if len(facerect) > 0:
                        for rect in facerect:
#                                cv2.rectangle(frame, tuple(rect[0:2]), tuple(rect[0:2]+rect[2:4]), (0, 0, 255), thickness = 2)
#                                print(tuple(rect[0:2]))
#                                print(tuple(rect[0:2]+rect[2:4]))
                                resized_ol_image = resize_image(img, rect[2], rect[3])
                                frame = overlayOnPart(frame, resized_ol_image, rect[0], rect[1])

                scale1 = 2
                frameheight = frame.shape[0]
                framewidth = frame.shape[1]
                frame = cv2.resize(frame,(int(framewidth*scale1),int(frameheight*scale1)))
                yframe = cv2.flip(frame, 1)
                cv2.imshow('yframe', yframe)

                if cv2.waitKey(1) & 0xFF == ord('q'):
                        break

        capture.release()
        cv2.destroyAllWindows()

except:
        import sys
        print("Error:", sys.exc_info()[0])
        print(sys.exc_info()[1])
        import traceback
        print(traceback.format_tb(sys.exc_info()[2]))
        

