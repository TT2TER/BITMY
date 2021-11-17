# code with vscode
## VScode配置流程


#### 211116更新
    * 下载vscode 勾选添加path和添加到右键菜单//方便
   ![图片](https://user-images.githubusercontent.com/93923763/141787540-641b1d28-5b4f-4a6a-9a37-f673fa068748.png)

    * 这一步完全摆烂了，找了个自动配置脚本 https://vscch3.vercel.app/ 连接上用网盘下载，然后跟着视频教程(在最后配置的时候先选中新手推荐配置//为了初始化自定义设置，然后再选用自定义，修改如图C语言即可）
   ![图片](https://user-images.githubusercontent.com/93923763/141789579-3ef85007-1555-4b86-8aa7-618ad24e50b9.png)

    * 配置完成后打开vscode弹出的对话框如下图勾选
   ![图片](https://user-images.githubusercontent.com/93923763/141789913-b4cf19f2-8ad6-46d1-955a-f028d19bc163.png)

    * 右下角install（完全可以选择不安装） 
   ![图片](https://user-images.githubusercontent.com/93923763/141790092-a12c57ae-044a-42c5-8fe4-50f6a650e5d0.png)
    
    * 将这个.json中的C18改为C17即可
   ![图片](https://user-images.githubusercontent.com/93923763/141791134-a1db92c6-aa57-41c3-8e40-8779b7349de7.png)

    * 按F6看看有没有hello world
    * ***务必重启计算机***
    * 关于Windowspowershell中如图乱码问题，
   ![图片](https://user-images.githubusercontent.com/93923763/141790471-54f55db8-05b0-4175-8891-5c3635ad9a2f.png)

   参见：[powershell乱码](#jump)

    * 其他的推荐插件 Chinese (Simplified) (简体中文) Language Pack for Visual Studio Code, code runner, bracket pair colorizer 2, indent-rainbow, one dark pro, power mode, vsc netease music 以上插件百度名称就有教程
    其中关于code runner插件，安装之后在插件设置中去寻找 run in terminal
    
   ![图片](https://user-images.githubusercontent.com/93923763/142205097-b5c2fff9-b375-40e8-9451-5ed89f951c42.png)
   ![图片](https://user-images.githubusercontent.com/93923763/142205715-5c68cccd-9078-4b37-89df-279f7d85c0da.png)


## GitHub with VScode 
##### 安装上GitHub的代理
    * Dev-sidecar 下载链接如下
    
   [Dev-sidecar下载链接](https://gitee.com/docmirror/dev-sidecar#%E4%BA%8C%E5%BF%AB%E9%80%9F%E5%BC%80%E5%A7%8B)

    * 在快速开始中下载后按照网站教程安装证书
[使用火狐浏览器无法打开github情况解决办法](#火狐浏览器github)

##### 安装Git
    * 安装Git，方法见如下链接
[Git安装](#jump1)

##### 安装客户端
    * 从GitHub官网上下载github desktop （用它来克隆初始化本地库）
    * 登陆Github.com 新建一个仓库
![图片](https://user-images.githubusercontent.com/93923763/142030672-79bafe46-5cb7-4a6b-ae72-6af1fecb9c1a.png)
![图片](https://user-images.githubusercontent.com/93923763/142030957-204f64f5-d1d9-45ee-bd33-d82047b5cdf7.png)
     
    * 在本地克隆在线库
![图片](https://user-images.githubusercontent.com/93923763/142031352-f0fe9daf-7ef2-4060-8de5-2807f7caef89.png)
![图片](https://user-images.githubusercontent.com/93923763/142031787-16252c83-3a9a-43ae-b576-727568a0aea2.png)
    
    * 界面介绍（拉取就是从仓库上下载文件覆盖本地，HISTORY是历史版本，open in vscode 顾名思义）
![图片](https://user-images.githubusercontent.com/93923763/142032105-34613fc8-41da-4ee5-871b-0991f0839a18.png)

##### 将之前配置好的vscode工作文件夹复制进这个文件夹中
##### 在vscode中更新文件方法

    * 文件更改后在左侧源代码管理会显示
![图片](https://user-images.githubusercontent.com/93923763/142032915-4e316f35-5e89-44f3-9595-b52aae098ac7.png)
    
    * 第一步 加号将文件暂存，第二步输入对这次更新的描述，第三步对钩提交
![图片](https://user-images.githubusercontent.com/93923763/142033120-b86b7c31-9b08-4898-a3e2-b866bd5f7b24.png)

    * 最后推送到github上
![图片](https://user-images.githubusercontent.com/93923763/142033567-2b7c3324-1c87-43b1-a85d-d5793c549b2f.png)

    * 如果远程仓库（github上）有更新，在本地执行拉取即可
![图片](https://user-images.githubusercontent.com/93923763/142033846-0c62c62f-847a-46be-b791-0f27a6d46b74.png)

    按这个做仅仅是能使用，而非理解，可以自行查询相关资料

## powershell乱码 <span id="jump"></span> 
    * 使用 Powerline 进行样式化，并使用更纱黑体 可从清华镜像站下载:https://mirrors.tuna.tsinghua.edu.cn/github-release/be5invis/Sarasa-Gothic/
    * Sarasa Gothic / 更纱黑体：基于Noto Sans，全宽引号
      Sarasa UI / 更纱黑体 UI：基于Noto Sans窄引号
      Sarasa Mono T / 等距更纱黑体 T：基于Iosevka，有连字，全宽破折号
      Sarasa Mono / 等距更纱黑体：基于Iosevka，有连字，半宽破折号
      Sarasa Term：基于Iosevka，无连字，半宽破折号
      包含汉字字形：
      CL：传统字形
      SC：简体中文
      TC：台湾繁体中文
      J：日文
      K：韩文
      HC：香港繁体中文

   ![图片](https://user-images.githubusercontent.com/93923763/141820127-c5aa720f-e939-4279-81a8-d6555d270e8d.png)

   ![图片](https://user-images.githubusercontent.com/93923763/141820406-d253e9ed-262c-46db-bf4a-670e2bd062a6.png)


   ![图片](https://user-images.githubusercontent.com/93923763/141821501-be938d5a-b49a-40b5-a7b8-4c3efc7ca518.png)

    * 下载解压并且找到上图所示的ttf文件，安装

   ![图片](https://user-images.githubusercontent.com/93923763/141824661-c996e090-1e02-4b3a-9379-f76c8706ff98.png)

    * vscode中F6调出对应的powershell，属性，改字体

   ![图片](https://user-images.githubusercontent.com/93923763/141822039-3f0575e0-4df3-4994-ac4d-68e65a8cd2d0.png)

    * bingo！


## 使用火狐浏览器无法打开github情况解决办法 <span id="火狐浏览器github"></span>
   
    火狐浏览器：火狐浏览器不走系统的根证书，需要在选项中添加根证书
    1、火狐浏览器->选项->隐私与安全->证书->查看证书
    2、证书颁发机构->导入
    3、选择证书文件C:\Users(用户)\Administrator(你的账号)\.dev-sidecar\dev-sidecar.ca.crt（Mac或linux为~/.dev-sidecar目录）
    4、勾选信任由此证书颁发机构来标识网站，确定即可

## Git简单安装 <span id="jump1"></span>
    * install git form
[git](https://git-scm.com/downloads)

    * 一路默认安装
