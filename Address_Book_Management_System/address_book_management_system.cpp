#include <iostream>
#include <string>
#define MAX 1000


// 联系人结构体
struct Person {
    std::string m_Name;  // 姓名
    int m_Sex;  // 性别；1 为男，2 为女
    int m_Age;  // 年龄
    std::string m_Phone;  // 电话
    std::string m_Address;  // 家庭住址
};


// 通讯录结构体
struct Addressbook {
    Person personArray[MAX];  // 通讯录中保存的联系人数组
    int m_Size;  // 通讯录中当前记录的联系人数
};


// 菜单界面
void showMenu() {
    std::cout << "***************************" << std::endl;
    std::cout << "*****  1、添加联系人  *****" << std::endl;
    std::cout << "*****  2、显示联系人  *****" << std::endl;
    std::cout << "*****  3、删除联系人  *****" << std::endl;
    std::cout << "*****  4、查找联系人  *****" << std::endl;
    std::cout << "*****  5、修改联系人  *****" << std::endl;
    std::cout << "*****  6、清空联系人  *****" << std::endl;
    std::cout << "*****  0、退出通讯录  *****" << std::endl;
    std::cout << "***************************" << std::endl;
}


// 添加联系人
void addPerson(Addressbook* addrb) {
    if (addrb->m_Size == MAX) {
        std::cout << "通讯录已满，无法添加新的联系人！" << std::endl;
        return;
    }
    else {
        // 姓名
        std::string name;
        std::cout << "请输入姓名（字符数不超过 30）：" << std::endl;
        while (true) {
            std::cin >> name;
            if (name.length() <= 20) {
                addrb->personArray[addrb->m_Size].m_Name = name;
                break;
            }
            else {
                std::cout << "字符数已超过 30，请重新输入：" << std::endl;
            }
        }
        
        // 性别
        int sex;
        std::cout << "请输入性别（1 == 男性，2 == 女性）：" << std::endl;
        while (true) {
            std::cin >> sex;
            if (sex == 1 || sex == 2) {
                addrb->personArray[addrb->m_Size].m_Sex = sex;
                break;
            }
            else {
                std::cout << "输入错误，请重新输入：" << std::endl;
            }
        }
        
        // 年龄
        int age;
        std::cout << "请输入年龄：" << std::endl;
        while (true) {
            std::cin >> age;
            if (age >= 0 && age <= 150) {
                addrb->personArray[addrb->m_Size].m_Age = age;
                break;
            }
            else {
                std::cout << "年龄大小不符，请重新输入：" << std::endl;
            }
        }
        
        // 电话
        std::string phone;
        std::cout << "请输入电话：" << std::endl;
        while (true) {
            std::cin >> phone;
            if (phone.length() == 11) {
                addrb->personArray[addrb->m_Size].m_Phone = phone;
                break;
            }
            else {
                std::cout << "电话位数不符，请重新输入：" << std::endl;
            }
        }
        
        // 家庭住址
        std::string address;
        std::cout << "请输入家庭住址（字符数不超过 100）：" << std::endl;
        while (true) {
            std::cin >> address;
            if (address.length() <= 100) {
                addrb->personArray[addrb->m_Size].m_Address = address;
                break;
            }
            else {
                std::cout << "字符数已超过 100，请重新输入：" << std::endl;
            }
        }
    }
    
    addrb->m_Size++;
    
    std::cout << "联系人添加成功！" << std::endl;
    
    system("pause");
    system("cls");
}


// 显示联系人
void showPerson(Addressbook* addrb) {
    if (addrb->m_Size == 0) {
        std::cout << "当前记录为空！" << std::endl;
    }
    else {
        for (int i = 0; i < addrb->m_Size; i++) {
            std::cout << "姓名：" << addrb->personArray[i].m_Name << "\t";
            std::cout << "性别：" << (addrb->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            std::cout << "年龄：" << addrb->personArray[i].m_Age << "\t";
            std::cout << "电话：" << addrb->personArray[i].m_Phone << "\t";
            std::cout << "家庭住址：" << addrb->personArray[i].m_Address << std::endl;
        }
    }
    
    system("pause");
    system("cls");
}


// 检测联系人
int detectPerson(Addressbook* addrb, std::string name) {
    for (int i = 0; i < addrb->m_Size; i++) {
        if (addrb->personArray[i].m_Name == name) {
            return i;
        }
    }
    
    return -1;
}


// 删除联系人
void deletePerson(Addressbook* addrb, std::string name, int num) {
    if (num == addrb->m_Size - 1) {
        addrb->m_Size--;
    }
    else {
        for (int i = num; i < addrb->m_Size; i++) {
            addrb->personArray[i] = addrb->personArray[i + 1];  // 数据前移
        }
    }
    
    addrb->m_Size--;
    
    std::cout << "联系人删除成功！" << std::endl;
    
    system("pause");
    system("cls");
}


// 查找联系人
void findPerson(Addressbook* addrb, std::string name, int num) {
    std::cout << "姓名：" << addrb->personArray[num].m_Name << "\t";
    std::cout << "性别：" << (addrb->personArray[num].m_Sex == 1 ? "男" : "女") << "\t";
    std::cout << "年龄：" << addrb->personArray[num].m_Age << "\t";
    std::cout << "电话：" << addrb->personArray[num].m_Phone << "\t";
    std::cout << "家庭住址：" << addrb->personArray[num].m_Address << std::endl;
    
    system("pause");
    system("cls");
}


// 修改联系人
void modifyPerson(Addressbook* addrb, int num) {
    int flag;
    
    while (true) {
        std::cout << "请输入 flag 的值（1 表示修改姓名，2 表示修改性别，3 表示修改年龄，4 表示修改电话，5 表示修改家庭住址，0 表示退出修改）：" << std::endl;
        std::cin >> flag;
        
        if (flag == 1) {
            std::string new_name;
            std::cout << "请输入新的姓名：" << std::endl;
            while (true) {
                std::cin >> new_name;
                if (new_name.length() <= 30) {
                    addrb->personArray[num].m_Name = new_name;
                    break;
                }
                else {
                    std::cout << "字符数已超过 30，请重新输入：" << std::endl;
                }
            }
        }
        else if (flag == 2) {
            int new_sex;
            std::cout << "请输入新的性别：" << std::endl;
            while (true) {
                std::cin >> new_sex;
                if (new_sex == 1 || new_sex == 2) {
                    addrb->personArray[num].m_Sex = new_sex;
                    break;
                }
                else {
                    std::cout << "输入错误，请重新输入：" << std::endl;
                }
            }
        }
        else if (flag == 3) {
            int new_age;
            std::cout << "请输入新的年龄：" << std::endl;
            while (true) {
                std::cin >> new_age;
                if (new_age >= 0 && new_age <= 150) {
                    addrb->personArray[num].m_Age = new_age;
                    break;
                }
                else {
                    std::cout << "年龄大小不符，请重新输入：" << std::endl;
                }
            }
        }
        else if (flag == 4) {
            std::string new_phone;
            std::cout << "请输入新的电话：" << std::endl;
            while (true) {
                std::cin >> new_phone;
                if (new_phone.length() == 11) {
                    addrb->personArray[num].m_Phone = new_phone;
                    break;
                }
                else {
                    std::cout << "电话位数不符，请重新输入：" << std::endl;
                }
            }
        }
        else if (flag == 5) {
            std::string new_address;
            std::cout << "请输入新的家庭住址：" << std::endl;
            while (true) {
                std::cin >> new_address;
                if (new_address.length() <= 100) {
                    addrb->personArray[num].m_Address = new_address;
                    break;
                }
                else {
                    std::cout << "字符数已超过 100，请重新输入：" << std::endl;
                }
            }
        }
        else if (flag == 0) {
            break;
        }
    }
    
    std::cout << "联系人信息修改成功！" << std::endl;
    
    system("pause");
    system("cls");
}


// 清空联系人
void cleanPerson(Addressbook* addrb) {
    if (addrb->m_Size == 0) {
        std::cout << "通讯录为空！" << std::endl;
    }
    else {
        addrb->m_Size = 0;
        std::cout << "联系人已清空！" << std::endl;
    }
    
    system("pause");
    system("cls");
}


// 功能选择
int funcSelect(int select, Addressbook* addrb) {
    switch (select)
    {
        case 1:  // 1、添加联系人
            addPerson(addrb);
            break;
        case 2:  // 2、显示联系人
            showPerson(addrb);
            break;
        case 3:  // 3、删除联系人
            {
                std::cout << "请输入要删除的联系人的姓名：" << std::endl;
                std::string name;
                std::cin >> name;
                if (detectPerson(addrb, name) == -1) {
                    std::cout << "查无此人！" << std::endl;
                }
                else {
                    int num = detectPerson(addrb, name);
                    deletePerson(addrb, name, num);
                }
            }
            break;
        case 4:  // 4、查找联系人
            {
                std::cout << "请输入要查找的联系人的姓名：" << std::endl;
                std::string name;
                std::cin >> name;
                if (detectPerson(addrb, name) == -1) {
                    std::cout << "查无此人！" << std::endl;
                }
                else {
                    int num = detectPerson(addrb, name);
                    findPerson(addrb, name, num);
                }
            }
            break;
        case 5:  // 5、修改联系人
            {
                std::cout << "请输入要修改的联系人的姓名：" << std::endl;
                std::string name;
                std::cin >> name;
                if (detectPerson(addrb, name) == -1) {
                    std::cout << "查无此人！" << std::endl;
                }
                else {
                    int num = detectPerson(addrb, name);
                    modifyPerson(addrb, num);
                }
            }
            break;
        case 6:  // 6、清空联系人
            cleanPerson(addrb);
            break;
        case 0:  // 0、退出通讯录
            std::cout << "您已退出通讯录，欢迎下次使用！" << std::endl;
            break;
    }
    
    return select;
}


int main() {
    Addressbook addrb;
    addrb.m_Size = 0;
    int select;
    int res;
    
    while (true) {
        showMenu();
        
        std::cin >> select;
        res = funcSelect(select, &addrb);
        if (res == 0) {
            break;
        }
    }
    
    system("pause");
    
    return 0;
}

