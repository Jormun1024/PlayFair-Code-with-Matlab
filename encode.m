function ciphertext=encode()
%key 密钥
%irrelevance 无关字符
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
right = 1;
len = 'a'-'A';
while (right == 1)
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
        plaintext=input("请输入明文（英文字符）：\n",'s');
        plaintext=abs(plaintext);
        irrelevance=input("请输入一个无关字符：\n",'s');
        irrelevance=abs(irrelevance);
        if irrelevance >= abs('a')
            irrelevance = irrelevance - len;
        end
        %把所输入的明文转化为大写字母
        for k = 1:length(plaintext(:))
            if plaintext(k) >= abs('a')
                plaintext(k) = plaintext(k) - len;
            end
        end
        %把明文中的J都变为I
        for k = 1:length(plaintext(:))
            if plaintext(k) == 'J'
                plaintext(k) = 'I';
            end
        end
        %为明文添加必要的无关字符以防止同一组的两个字符相同
        for k = 1:2:length(plaintext(:))-1
            if plaintext(k) == plaintext(k+1)
                for t = length(plaintext(:)):-1:k+1
                    plaintext(t+1) = plaintext(t);
                end
                plaintext(k+1) = irrelevance;
            end
        end
        %若明文有奇数个字符，则添加一个无关字符以凑够偶数个
        if rem(length(plaintext(:)),2) ~= 0
            plaintext(length(plaintext(:))+1) = plaintext(length(plaintext(:)));
            %字符串结尾赋'\0'
            plaintext(length(plaintext(:))) = irrelevance;
            %明文串尾插入无关字符
        end
        disp("经转换后，明文为：");
        for k = 1:2:length(plaintext(:))
            disp(char(plaintext([k,k+1])));
        end
        disp("明文长度为：");
        disp(length(plaintext(:)));
        %明文编译为密文
        for k=1:length(plaintext(:))
            for a=0:4
                for b=0:4
                    if plaintext(k)==ch(5*a+b+1)
                        m(k)=a;
                        n(k)=b;
                    end
                end
            end
        end
        for k=1:2:length (plaintext(:))
            if m(k)==m(k+1)
                ciphertext(k)=ch(5*m(k)+rem(n(k)+1,5)+1);
                ciphertext(k+1)=ch(5*m(k+1)+rem(n(k+1)+1,5)+1);
            elseif n(k)==n(k+1)
                ciphertext(k)=ch(5*rem(m(k)+1,5)+n(k)+1);
                ciphertext(k+1)=ch(5*rem(m(k+1)+1,5)+n(k+1)+1);
            else
                ciphertext(k)=ch(5*m(k)+n(k+1)+1);
                ciphertext(k+1)=ch(5*m(k+1)+n(k)+1);
            end
        end
        disp("经加密后，密文为：");
        for k = 1:2:length(ciphertext(:))
            disp(char(ciphertext([k,k+1])));
        end
    else
        break
    end
end