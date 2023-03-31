clc;
clear;

exit=0;
while exit==0
    mode=input("请选择模式:（1、加密；2、解密；3、退出）\n");
    if mode==1
        ciphertext=encode();
    elseif mode==2
        plaintext=decode();
    elseif mode==3
        exit=1;
    else
        disp("<Error>无效字符，请重新选择操作");
        disp(" ");
    end
end