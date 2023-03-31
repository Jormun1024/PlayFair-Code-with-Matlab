function plaintext=decode()
%key 密钥
%plaintext 明文
%ciphertext 密文

letter=['A' 'B' 'C' 'D' 'E'; 
        'F' 'G' 'H' 'I' 'K';
        'L' 'M' 'N' 'O' 'P';
        'Q' 'R' 'S' 'T' 'U';
        'V' 'W' 'X' 'Y' 'Z'];
letter=letter';
letter=abs(letter);
flag=zeros(5);
ch=zeros(5);
key=input("请输入密钥：\n",'s');
key=abs(key);
l=length(key(:));
m=zeros(100);
n=zeros(100);
r=1;
right = 1;
len = 'a'-'A';
while right == 1
    %把所输入的密钥转化为大写字母
    for i = 1:length(key(:))
        if key(i)> abs('z') || key(i)<abs('a')
            disp("请重新选择操作");
            right = 0; 
            break;
        else
            key(i) = key(i) - len;
        end
    end
    if right == 1
    %把密钥中的J都变为I
        for i = 1: length(key(:))
            if key(i) == abs('J') 
                key(i) = abs('I');
            end
        end
        %把密钥中的字母填入到矩阵中，并把该字母标记为已用
        for i=1:l
            for j=1:25
                if key(i) == letter(j)
                    ch(i) = letter(j);
                    flag(j) = 1;
                end
            end
        end
        %按字母表顺序把未用字母依次填入到矩阵中
        for j=1:25
            if flag(j) == 0
                l=l+1;
                ch(l) = letter(j);
                flag(j) = 1;
            end
        end
        disp("密钥填充后的矩阵为： ");
        disp(char(ch'));
        while r==1
            ciphertext=input("请输入密文（英文字符）：\n",'s');
            ciphertext=abs(ciphertext);
            %若密文有奇数个字符，则报错
            if rem(length(ciphertext(:)),2) ~= 0
                disp("<Error>密文字符可能缺失，请重新输入密文");
            else
                r=0;
            end
        end
        %把所输入的密文转化为大写字母
        for k = 1:length(ciphertext(:))
            if ciphertext(k) >= abs('a')
                ciphertext(k) = ciphertext(k) - len;
            end
        end
        disp("经转换后，密文为：");
        for k = 1:2:length(ciphertext(:))
            disp(char(ciphertext([k,k+1])));
        end
        disp("密文长度为：");
        disp(length(ciphertext(:)));
        %密文编译为明文
        for k=1:length(ciphertext(:))
            for a=0:4
                for b=0:4
                    if ciphertext(k)==ch(5*a+b+1)
                        m(k)=a;
                        n(k)=b;
                    end
                end
            end
        end
        for k=1:2:length (ciphertext(:))
            if m(k)==m(k+1)
                plaintext(k)=ch(5*m(k)+rem(n(k)+4,5)+1);
                plaintext(k+1)=ch(5*m(k+1)+rem(n(k+1)+4,5)+1);
            elseif n(k)==n(k+1)
                plaintext(k)=ch(5*rem(m(k)+4,5)+n(k)+1);
                plaintext(k+1)=ch(5*rem(m(k+1)+4,5)+n(k+1)+1);
            else
                plaintext(k)=ch(5*m(k)+n(k+1)+1);
                plaintext(k+1)=ch(5*m(k+1)+n(k)+1);
            end
        end
        disp("经解密后，明文为：");
        for k = 1:2:length(plaintext(:))
            disp(char(plaintext([k,k+1])));
        end
    else
        break
    end
end