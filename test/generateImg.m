close all;
clear all;
clc;

img = rgb2gray(imread('lena.bmp'));

hsize = 10;
sigma = 3;
K = fspecial('gaussian',hsize,sigma);

len = 10;
theta = 45;
%K = fspecial('motion',len,theta);

imgFilt = imfilter(img,K);

Pnoise = 0;
%NOISE = wgn(size(img,1),size(img,2),Pnoise);
%imgFilt = imgFilt + uint8(NOISE);

figure;
imagesc(imgFilt); colormap gray;

fileNameGauss =['gauss_hsize=',num2str(hsize),'_sigma=',num2str(sigma),'_Pnoise=',num2str(Pnoise),'.bmp'];
fileNameMot =['motion_len=',num2str(len),'_theta=',num2str(theta),'_Pnoise=',num2str(Pnoise),'.bmp'];
imwrite(imgFilt,fileNameGauss);