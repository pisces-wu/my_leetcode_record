import numpy as np
# 手写nms
class bbox:
    def __init__(self,x0,y0,x1,y1,score):
        self.x0=x0
        self.x1=x1
        self.y0=y0
        self.y1=y1
        self.score=score

def iou(bbox0,bbox1):
    x_min=max(bbox0.x0,bbox1.x0)
    y_min=max(bbox0.y0,bbox1.y0)
    x_max=min(bbox0.x1,bbox1.x1)
    y_max=min(bbox0.y1,bbox1.y1)
    if x_min>=x_max or y_min>=y_max:
        return 0
    i_area=(x_max-x_min)*(y_max-y_min)
    bbox0_area=(bbox0.x1-bbox0.x0)*(bbox0.y1-bbox0.y0)
    bbox1_area=(bbox1.x1-bbox1.x0)*(bbox1.y1-bbox1.y0)
    u_area=bbox0_area+bbox1_area-i_area
    return float(i_area)/float(u_area)

def nms(bboxes,k):
    bboxes=sorted(bboxes,key=lambda x:x.score,reverse=True)
    nms_list=[bboxes[0]]
    tmp_list=[]
    for i in range(k):
        for j in range(1,len(bboxes)):
            s_iou=iou(nms_list[-1],bboxes[j])
            if(s_iou<0.7):
                tmp_list.append(bboxes[j])
        if len(tmp_list)==0:
            return nms_list
        bboxes=tmp_list
        tmp_list=[]
        nms_list.append(bboxes[0])
    return nms_list
if __name__ == '__main__':
    box1=bbox(13, 22, 268, 367, 0.124648176)
    box2=bbox(18, 27, 294, 400, 0.35818103)
    box3=bbox(234, 123, 466, 678, 0.13638769)
    bboxes=[box1,box2,box3]
    ret=nms(bboxes,2)
    for i in range(len(ret)):
        print(ret[i].x0,ret[i].y0,ret[i].x1,ret[i].y1)
        print("\n")

# import numpy as np
#
# class Bounding_box:
#     def __init__(self, x1, y1, x2, y2, score):
#         self.x1 = x1
#         self.y1 = y1
#         self.x2 = x2
#         self.y2 = y2
#         self.score = score
#
# def get_iou(boxa, boxb):
#     max_x = max(boxa.x1, boxb.x1)
#     max_y = max(boxa.y1, boxb.y1)
#     min_x = min(boxa.x2, boxb.x2)
#     min_y = min(boxa.y2, boxb.y2)
#     if min_x <= max_x or min_y <= max_y:
#         return 0
#     area_i = (min_x - max_x) * (min_y - max_y)
#     area_a = (boxa.x2 - boxa.x1) * (boxa.y2 - boxa.y1)
#     area_b = (boxb.x2 - boxb.x1) * (boxb.y2 - boxb.y1)
#     area_u = area_a + area_b - area_i
#     return float(area_i) / float(area_u)
#
# def NMS(box_lists, k):
#     box_lists = sorted(box_lists, key=lambda x: x.score, reverse=True)
#     NMS_lists = [box_lists[0]]
#     temp_lists = []
#     for i in range(k):
#         for j in range(1, len(box_lists)):
#             iou = get_iou(NMS_lists[i], box_lists[j])
#             if iou < 0.7:
#                 temp_lists.append(box_lists[j])
#         if len(temp_lists) == 0:
#             return NMS_lists
#         box_lists = temp_lists
#         temp_lists = []
#         NMS_lists.append(box_lists[0])
#     return NMS_lists
#
# box1 = Bounding_box(13, 22, 268, 367, 0.124648176)
# box2 = Bounding_box(18, 27, 294, 400, 0.35818103)
# box3 = Bounding_box(234, 123, 466, 678, 0.13638769)
# box_lists = [box1, box2, box3]
# ret = NMS(box_lists, 2)
# for i in range(len(ret)):
#     print(ret[i].x1, ret[i].y1, ret[i].x2, ret[i].y2)
#     print("\n")
# # print(NMS_list)
