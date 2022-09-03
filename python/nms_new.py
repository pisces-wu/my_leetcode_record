class box:
    def __init__(self,x0,y0,x1,y1,score):
        self.x0=x0
        self.x1=x1
        self.y0=y0
        self.y1=y1
        self.score=score

def iou(box1,box2):
    x0=max(box1.x0,box2.x0)
    y0=max(box1.y0,box2.y0)
    x1=min(box1.x1,box2.x1)
    y1=min(box1.y1,box2.y1)
    if(x0>=x1 or y0>=y1): return 0
    inter=(y1-y0)*(x1-x0)
    union=(box1.x1-box1.x0)*(box1.y1-box1.y0)+(box2.x1-box2.x0)*(box2.y1-box2.y0)
    return  inter/(union-inter)

def nms(bboxes,k,thred):
    bboxes=sorted(bboxes,key=lambda x:x.score,reverse=True)
    nms_list=[bboxes[0]]
    tmp_list=[]
    for i in range(k):
        for j in range(1,len(bboxes)):
            iou_val=iou(nms_list[-1],bboxes[j])
            if(iou_val<=thred):
                tmp_list.append(bboxes[j])
        if(len(tmp_list)==0): return nms_list
        nms_list.append(tmp_list[0])
        bboxes=tmp_list
        tmp_list=[]
    return nms_list

if __name__ == '__main__':
    # box1 = box(13, 22, 268, 367, 0.1)
    # box2 = box(18, 27, 294, 400, 0.3)
    # box3 = box(234, 123, 466, 678, 0.1)
    box1 = box(10, 20, 300, 400, 0.1)
    box2 = box(20, 30, 300, 400, 0.3)
    box3 = box(200, 200, 500, 500, 0.1)
    bboxes=[box1,box2,box3]
    ret=nms(bboxes,2,0.7)
    for i in range(len(ret)):
        print(ret[i].x0," ",ret[i].y0," ",ret[i].x1," ",ret[i].y1)

# import numpy
# class bbox:
#     def __init__(self,x0,y0,x1,y1,score):
#         self.x0=x0
#         self.y0=y0
#         self.x1=x1
#         self.y1=y1
#         self.score=score
#
# def iou(box1,box2):
#     x0=max(box1.x0,box2.x0)
#     y0=max(box1.y0,box2.y0)
#     x1=min(box1.x1,box2.x1)
#     y1=min(box1.y1,box2.y1)
#     if(x0>=x1 or y0>=y1): return 0
#     inter=(x1-x0)*(y1-y0)
#     union=(box1.x1-box1.x0)*(box1.y1-box1.y0)+(box2.x1-box2.x0)*(box2.y1-box2.y0)
#     return inter/(union-inter)
# def nms(bboxes,k,thred=0.7):
#     tmp_list=[]
#     ret=[]
#     # sort(bboxes,key=lambda x:x.score,reversed=True)
#     bboxes=sorted(bboxes,key=lambda x:x.score,reverse=True)
#     ret.append(bboxes[0])
#     for i in range(k):
#         for j in range(len(bboxes)):
#             iou_val=iou(ret[-1],bboxes[j])
#             if(iou_val<thred):
#                 tmp_list.append(bboxes[j])
#         if(len(tmp_list)==0): return ret
#         ret.append(tmp_list[0])
#         bboxes=tmp_list[1::]
#         tmp_list=[]
#     return ret
# if __name__ == '__main__':
#     # box1=bbox(0,0,200,200,0.5)
#     # box2=bbox(20,20,300,300,0.2)
#     # box3=bbox(70,70,800,800,0.3)
#     box1 = bbox(13, 22, 268, 367, 0.124648176)
#     box2 = bbox(18, 27, 294, 400, 0.35818103)
#     box3 = bbox(234, 123, 466, 678, 0.13638769)
#     bboxes=[box1,box2,box3]
#     ret=nms(bboxes,2,0.7)
#     for i in range(len(ret)):
#         print(ret[i].x0," ",ret[i].y1," ",ret[i].x1," ",ret[i].y1)
