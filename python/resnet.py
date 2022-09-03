import  torch
import torchvision
resnet=torchvision.models.resnet50()
layers=list(resnet.children())
print(layers)
