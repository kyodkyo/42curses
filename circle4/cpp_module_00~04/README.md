# C++ Module 00 - 04

이 프로젝트는 C++의 객체 지향 프로그래밍(OOP) 개념을 학습하는 과정으로, 언어의 기본 문법부터 메모리 관리, 다형성, 클래스 상속과 추상화까지 폭넓게 다룹니다. 각 모듈은 이전 내용을 바탕으로 점진적으로 복잡한 주제를 소개하고 도전 과제를 통해 실력을 쌓도록 설계되었습니다.


## 개요

| 모듈        | 주요 주제                                                      | 과제 요약                                                                                       |
|-------------|----------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| **Module 00** | C++ 기본 문법, 클래스, 멤버 함수, 네임스페이스                 | 기본적인 문법과 OOP를 연습하기 위해 `megaphone` 및 `PhoneBook`과 같은 간단한 프로그램을 구현 |
| **Module 01** | 메모리 관리, 포인터와 참조, switch문                           | `Zombie` 무리 생성, 문자열 포인터 시뮬레이션, 텍스트 대체 도구 등을 통한 동적 메모리 작업 |
| **Module 02** | 연산자 오버로딩, 고정 소수점 수와 Orthodox Canonical Form      | 고정 소수점 연산을 지원하는 `Fixed` 클래스를 구현하고 복사 생성자, 소멸자, 연산자 오버로딩 구현 |
| **Module 03** | 상속 및 클래스 계층구조                                        | `ClapTrap`, `ScavTrap`, `FragTrap`과 같은 클래스 계층 구조를 만들고, 상속과 메서드 오버라이딩 |
| **Module 04** | 추상 클래스, 인터페이스, 다형성                                | 가상 함수, 추상 클래스 및 인터페이스 개념을 활용하여 `Animal` 클래스 계층 구조와 캐릭터의 Materia 시스템을 구현 |


---


## Module 00 : C++ 기본
**핵심 개념**
- 클래스, 네임스페이스, 생성자, `const` 키워드, 멤버 함수  


**과제**
- `megaphone`: 입력된 텍스트를 대문자로 변환하는 프로그램
- `PhoneBook`: 제한된 수의 연락처를 저장하는 콘솔 전화번호부
- `Account`: 간단한 은행 계좌 시스템을 구현하여 계좌 정보를 관리

##
## Module 01 : 메모리 할당 및 포인터
**핵심 개념**
- 메모리 할당, 참조 및 포인터, `switch` 문, 메모리 누수 방지  


**과제**
- `Zombie Horde`: 동적 메모리를 사용하여 여러 객체를 관리
- `문자열 포인터`: 포인터와 참조를 통해 메모리 주소를 다루는 연습
- `Sed Replacement`: 표준 `replace` 메서드를 사용하지 않고 텍스트 파일의 단어를 대체하는 프로그램


##
## Module 02 : 연산자 오버로딩과 고정 소수점 연산
**핵심 개념**
- 연산자 오버로딩, Orthodox Canonical Form, 고정 소수점 수  


**과제**
- `Fixed Class`: 고정 소수점 연산을 지원하는 클래스 구현
- `오버로딩`: `Fixed` 클래스의 산술 및 비교 연산자 구현
- `BSP`: 특정 점이 삼각형 내에 위치하는지 확인하는 프로그램


##
## Module 03 : 상속 및 확장된 클래스 기능
**핵심 개념**
- 상속, 생성자와 소멸자, 메서드 오버라이딩  


**과제**
- `ClapTrap, ScavTrap, FragTrap`: 기본 클래스에서 상속받아 기능을 확장하고, 각 클래스에 고유한 메서드 추가
- `DiamondTrap`: 다중 상속을 통해 두 클래스에서 파생된 클래스 구현


##
## Module 04 : 추상 클래스와 인터페이스
**핵심 개념**
- 추상 클래스, 순수 가상 함수, 다형성  


**과제**
- `Animal Class Hierarchy`: 추상 기반 클래스와 파생 클래스를 활용하여 동물 클래스 계층 구조 구현
- `Materia System`: 캐릭터의 인벤토리 시스템을 인터페이스와 함께 구현하여 다형성 실습


---
