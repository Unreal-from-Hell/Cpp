# 콜백 함수(CallBack Function)
> 호출될 함수를 알려주어 다른 프로그램 또는 다른 모듈에서 함수를 호출하게 하는 방법

 * 일반적으로 운영체제(OS)가 호출할 애플리케이션의 함수를 지정해 특정한 사건 또는 메시지가 발생했을 때
  호출되도록 지정할 수 있다

<br>

### ***그냥 함수 호출과 callback 함수 호출의 차이점은 `제어권`이다***
> callback 함수는 내가 필요할 때 호출해서 사용하는 것이 아닌 어떤 이벤트가 발생했을 때 나에게 알려달라고 하는 것이다
> * 즉, 호출되는 것



<br>

``` cpp
class Item
{
public:

public:
    int _itemId;
    int _rarity;
    int _ownerId;
};

// 함수 객체
class FindByOwnerId
{
public:
    bool operator()(const Item* item)
    {
        return (item->_ownerId == _ownerId);
    }
public:
    int _ownerId;
};

class FindByRarity
{
public:
    bool operator()(const Item* item)
    {
        return (item->_rarity == _rarity);
    }
public:
    int _rarity;
};

// 탬플릿 사용
template<typename T>
Item* FindItem(Item items[], int itemCount, T selector)
{
    for(int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];
        if(selector(item))
            return item;
    }
    return nullptr;
}


Item items[10];    
items[3]._ownerId = 100;
items[8]._rarity = 2;

FindByOwnerId functor1;
functor1._ownerId = 100;

FindByRarity functor2;
functor2._rarity = 1;

Item* item1 = FindItem(items, 10, functor1);
Item* item2 = FindItem(items, 10, functor2);

```