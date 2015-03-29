
// freetype 字体下载: http://ftp.gnu.org/gnu/freefont/freefont-ttf.zip

#include <iostream>
#include <vector>
#include <pngwriter.h>

#define PNG_WIDTH  800
#define PNG_HEIGHT 260
#define PNG_TEXT_FONT_PATH "/home/Yif/freefont-ttf/sfd/FreeSerif.ttf"
#define PNG_TEXT_FONT_SIZE 9

//int data[] = {2741 ,2342 ,2093 ,2101 ,1778 ,1930 ,1599 ,1659 ,2147 ,1200 ,1657 ,1733 ,1492 ,1817 ,1581 ,1526 ,1480 ,1432 ,1078 ,979 ,1148 ,887 ,920 ,888 ,901 , 13000 ,798 ,623 ,623 ,578 ,677 ,590 ,594 ,582 ,614 ,534 ,532 ,454 ,453 ,497 ,428 ,454 ,415 ,447 ,396 ,432 ,433 ,436 ,469 ,545 ,538 ,563 ,622 ,565 ,520 ,422 ,456 ,517 ,557 ,607 ,680 ,574 ,794 ,845 ,777 ,957 ,966 ,1288 ,1190 ,1156 ,1399 ,1410 ,1501 ,1563 ,1600 ,1909 ,1762 ,2001 ,1866 ,1946 ,2163 ,2047 ,2260 ,2315 ,2169 ,2066 ,2313 ,2434 ,2082 ,2365 ,2637 ,2717 ,2462 ,2638 ,2827 ,2901 ,3825 ,5895 ,5434 ,5202 ,4593 ,4578 ,4599 ,5286 ,5748 ,5708 ,5098 ,5929 ,5933 ,5885 ,5832 ,5968 ,5739 ,5915 ,5759 ,5986 ,5828 ,6128 ,6131 ,6147 ,6102 ,6130 ,6017 ,5615 ,5240 ,5685 ,5794 ,6004 ,5952 ,6052 ,6119 ,6032 ,6119 ,5909 ,5947 ,5804 ,6066 ,5532 ,5466 ,4998 ,4578 ,4516 ,4595 ,4405 ,4397 ,4261 ,4163 ,4260 ,4457 ,4495 ,4541 ,4475 ,4453 ,4457 ,4554 ,4594 ,4594 ,4552 ,4564 ,4567 ,4585 ,4593 ,4767 ,5345 ,5254 ,4960 ,4614 ,4872 ,5305 ,5291 ,5498 ,5555 ,4924 ,5620 ,5737 ,5464 ,5183 ,5628 ,5644 ,5379 ,5387 ,5478 ,5366 ,5214 ,5322 ,5335 ,5405 ,5493 ,5298 ,4996 ,5281 ,4995 ,5161 ,4853 ,4594 ,4863 ,4919 ,4803 ,4833 ,4886 ,4825 ,4850 ,4835 ,4636 ,4737 ,4597 ,4597 ,4594 ,4595 ,4594 ,4457 ,4230 ,4222 ,4300 ,4257 ,3793 ,3490 ,3418 ,3223 ,3439 ,3609 ,4474 ,4013 ,3821 ,4441 ,3939 ,3976 ,4185 ,4153 ,4198 ,4394 ,4281 ,4320 ,4334 ,4356 ,4188 ,4487 ,4392 ,4440 ,4412 ,4385 ,4593 ,4498 ,4592 ,4640 ,5060 ,4867 ,4868 ,4665 ,5223 ,5490 ,5582 ,5575 ,5104 ,5347 ,5952 ,5811 ,5553 ,5601 ,5832 ,5570 ,5593 ,5417 ,5879 ,5137 ,5623 ,5066 ,4932 ,4680 ,4674 ,4628 ,4534 ,4591 ,4581 ,4576 ,4280 ,4250 ,4060 ,3956 ,3305 ,3046 ,2960 ,2562 ,2740 ,2468 ,2760 ,2213, 2506};
//int data[] = {1313,924,798,670,703,624,569,502,442,408,352,302,296,272,244,244,227,210,195,208,189,182,182,191,214,208,253,193,181,223,426,439,386,369,412,463,617,713,788,1096,1145,1230,1206,1410,1460,1569,1624,1716,2475,2825,2874,3159,3102,3368,3255,3162,3233,3215,3118,3125,3161,3167,3141,3188,3276,3127,3139,3001,3135,3049,2940,2805,2604,2748,3004,2857,2949,2922,3115,3039,3045,3307,3158,3111,3080,3134,3037,3030,2976,3033,3093,2999,3076,3073,2982,3118,3089,3160,3222,3228,3239,3310,3067,3257,3430,3176,3110,3278,2932,3053,2939,2989,3153,3128,3147,3283,3474,3577,3779,3660,3716,4042,4874,4599,4227,4924,4590,4573,4731,6551,5092,4509,5091,5505,5127,4088,3659,3340,3481,3746,3651,3521,3343,2979,2309,938,905,1130,866,614,619,568,516,438,438,337,301,294,265,237,263,219,203,171,190,285,280,216,225,250,244,279,269,339,269,300,320,427,468,584,697,843,957,1134,1345,1452,1514,1589,1704,1814,1839,2017,2557,2779,2933,3085,3101,3004,3113,2984,3185,3647,3241,3138,2993,3176,3228,3197,3138,3044,2991,3063,3254,3116,3069,2997,2867,2857,2934,2902,2922,2920,2997,3030,2817,2879,2837,2967,2737,2825,3045,2793,2663,2775,2805,2871,2750,2730,2830,2709,2766,2716,3066,2858,2837,2845,2797,2856,3046,2788,2802,2757,2804,2836,2894,2944,2896,3146,3381,3265};
//int data_len = 260;

using namespace std;

int main(int argc, char* argv[])
{
    // 参数
    char* png_path = argv[1];
    int step_x = strtol(argv[2], NULL, 0);

    // 读取数据
    std::vector<int> data;
    int number = 0, max = 0, data_len = 0;
    while (scanf("%u", &number) != EOF)
    {
        data.push_back(number);
        if (number > max)
        {
            max = number;
        }
    }
    data_len = data.size();

    pngwriter png(PNG_WIDTH, PNG_HEIGHT, 1.0, png_path);

    // 外边框
    png.line(1,         1,          PNG_WIDTH, 1,          0x9900, 0xbb00, 0xe800);
    png.line(1,         1,          1,         PNG_HEIGHT, 0x9900, 0xbb00, 0xe800);
    png.line(1,         PNG_HEIGHT, PNG_WIDTH, PNG_HEIGHT, 0x9900, 0xbb00, 0xe800);
    png.line(PNG_WIDTH, 1,          PNG_WIDTH, PNG_HEIGHT, 0x9900, 0xbb00, 0xe800);

    // 背景色
    for (int y = 2; y < PNG_HEIGHT; ++y)
    {
        png.line(2, y, PNG_WIDTH-1, y, 0xcf00, 0xe900, 0xfb00);
    }

    // 图形区(左下坐标: 70,46, 右上坐标: 780,215)
    int img_width = 720;
    int x_left_down = 61, x_right_up = 61 + 720;
    int y_left_down = 46, y_right_up = 46 + 170;
    for (int y = y_left_down; y <= y_right_up; ++y)
    {
        png.line(x_left_down, y, x_right_up, y, 1.0, 1.0, 1.0);
    }

    // Y轴刻度线数量上限
    int step_y_max = 7;

    // 计算Y轴最佳刻度值、刻度线数量
    int stepnum = 0;
    int step_y = 0;
    int log10val = floor(log10(max));
    for (int i = log10val - 1; i <= log10val; ++i)
    {
        int powval = pow(10, i);

        int tmp[] = {1, 2, 5};
        for (int base = 0; base < 3; ++base)
        {
            stepnum = tmp[base] * powval;
            step_y = ceil(max * 1.0 / stepnum);
            if (step_y <= step_y_max)
            {
                // 还需要最大值距离最大刻度不少于刻度值的1/3
                int delta = (step_y * stepnum) - max;
                if (delta < stepnum * 0.33)
                {
                    step_y += 1;
                }
                if (step_y <= step_y_max)
                {
                    break;
                }
            } 
        }
        if (step_y <= step_y_max)
        {
            // found!!!
            break;
        }
    }
    printf("maxval:[%d], log10:[%d], stepnum:[%d], step_y:[%d]\n"
           , max, log10val, stepnum, step_y);

    // 绘制Y轴刻度线
    int step_h = ((PNG_HEIGHT - 2 * 45)) / step_y;
    for (int i = 1; i <= step_y; ++i)
    {
        int y = y_left_down + i * step_h;
        // 刻度线
        png.line(x_left_down, y, x_right_up, y, 0xdd00, 0xdd00, 0xdd00);
        // 刻度点
        png.line(x_left_down, y, x_left_down + 3,  y, 0.0, 0.0, 0.0);

        // 刻度值
        char step[32] = {0};
        snprintf(step, sizeof(step), "%d", i * stepnum);
        png.plot_text(const_cast<char*>(PNG_TEXT_FONT_PATH), PNG_TEXT_FONT_SIZE
                      , x_left_down - 35, y - 5, 0
                      , step
                      , 0, 0, 0);
    }
    
    // X轴刻度线
    //int step_x = 21;
    if(step_x <= 0) step_x = 24;
    int step_w = ((PNG_WIDTH - 60 - 20)) / step_x;
    for (int i = 1; i <= step_x; ++i)
    {
        int x = x_left_down + i * step_w;
        //x = x_left_down + i * 28.54;
        // 刻度线
        png.line(x, y_left_down, x, y_right_up, 0xdd00, 0xdd00, 0xdd00);
        // 刻度点
        png.line(x, y_left_down, x, y_left_down + 3,  0.0, 0.0, 0.0);
    }

    // 坐标轴
    png.line(x_left_down, y_left_down, x_left_down,  y_right_up,  0.0, 0.0, 0.0);
    png.line(x_left_down, y_left_down, x_right_up,   y_left_down, 0.0, 0.0, 0.0);

    // 画拆线
    int x_max = 0, y_max = 0;
    for (int i = 1; i < data_len; ++i)
    {
        // 当前点
        int x_cur = x_left_down + (i)*(img_width*1.0/data_len);
        int y_cur = y_left_down + (data[i]/(step_y*stepnum/(y_right_up-y_left_down)));

        // 前一个点
        int x_pre = x_left_down + (i-1)*(img_width*1.0/data_len);
        int y_pre = y_left_down + (data[i-1]/(step_y*stepnum/(y_right_up-y_left_down)));

        // 画线
        png.line(x_pre, y_pre+0, x_cur, y_cur+0, 0x6600, 0xa200, 0x6600); 
        png.line(x_pre, y_pre+1, x_cur, y_cur+1, 0x6600, 0xa200, 0x6600);
        png.line(x_pre, y_pre-1, x_cur, y_cur-1, 0x6600, 0xa200, 0x6600);    

        // 峰值位置，后面标红
        if(data[i] == max)
        {
            x_max = x_cur;
            y_max = y_cur;
        }       
    }
    // 标红峰值
    png.line(x_max, y_left_down, x_max, y_right_up, 0xff00, 0, 0);

    //  保存
    png.close();
    return 0;
}
