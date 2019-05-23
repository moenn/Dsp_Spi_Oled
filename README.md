### Dsp_Spi_Oled 库
这个库可让你使用 TI 公司的 DSP 芯片通过串行通信方式控制 0.96英寸 128\*64 OLED 屏幕的**英文**显示。 程序中未使用 DSP 的 SPI 模块，而是采用 GPIO 口产生下降沿来送出串行数据的方式。

测试环境: ccsv8, tms320f28335    



### 如何配置
##### 硬件连接

|OLED|DSp|
|---|---|
| D0(SLK) | GPIO59 |
| D1(SDA) | GOIO60 |
| RES | GOIO61 |
| DC | GOIO62 |
| CS | GOIO63 |

当然你的 OLED 还要接上电源。如果你使用的OLED没有 CS 片选引脚，那么不接。如果你想更改用于连线的 GPIO 引脚，那么替换 `my_oled.c` 中相应引脚的宏定义。 


##### 软件配置
1. 安装[c2000ware](http://www.ti.com/tool/C2000WARE)。
2. 在 ccs 中新建 Test_Oled 空白工程，不带 main.c。
3. 添加 include 路径。
在 Test_Oled 工程上右键 => properties => Include Options => Add dir to #include search path, 点击 add.. 图标 => browse，然后添加 ```C:\ti\c2000\C2000Ware_<version>\device_support\f28<device_model>\common\include``` 。添加完成后，继续添加 ```C:\ti\c2000\C2000Ware_<version>\device_support\f28<device_model>\headers\include```。然后应用并更改。

	*<> 括起来的为你需要更改的，视你的 c2000ware 版本和芯片型号而定。ti 文件夹一般默认安装在 C盘，如果你装在了其他位置，那么需要更改相应的路径。*

4. 添加 c2000 中的源文件和头文件。
在 Test_Oled 工程上右键 => add file, 然后添加以下文件

	|要添加的文件|路径|
	|---|---|
	| 28xxx_RAM_lnk.cmd | `C:\ti\c2000\C2000Ware_<version>\device_support\f28<device_model>\common\cmd` |
	| DSP2833x_ADC_cal.asm<br>DSP2833x_SysCtrl.c<br>DSP2833x_usDelay.asm | `C:\ti\c2000\C2000Ware_<version>\device_support\f28<device_model>\common\source` |
	| DSP2833x_Headers_nonBIOS.cmd  | `C:\ti\c2000\C2000Ware_<version>\device_support\f28<device_model>\headers\cmd` |
	| DSP2833x_GlobalVariableDefs.c | `C:\ti\c2000\C2000Ware_<version>\device_support\f28<device_model>\headers\source`|

5. 添加本仓库中的所有文件, 与上一步骤相同

	| 要添加的文件   | 路径 |
	|----------------|------|
	| main.c         |      |
	| my_character.c |      |
	| my_character.h |      |
	| my_oled.c      |      |
	| my_oled.h      |      |

最终项目目录类似下图: 

![项目目录](https://raw.githubusercontent.com/moenn/Dsp_Spi_Oled/master/project_view.png)

### 使用 
编译下载，观察 OLED 是否显示。 `main.c` 中包含7个示例函数，通过更改`#define EXAMPLE_SELECT 1` 中的宏值(1-7)，来激活相应函数。