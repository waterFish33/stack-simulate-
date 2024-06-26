#include "Stack.h"

// 初始化栈 
void StackInit(Stack* ps) {
	assert(ps);
	ps->_capacity = 0;
	ps->_a = NULL;
	StackExtend(ps);
	ps->_top = 0;

}
// 入栈 
void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	if (ps->_capacity == ps->_top) {
		StackExtend(ps);
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// 出栈 
void StackPop(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));

	ps->_top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_a[ps->_top-1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps) {
	assert(ps);
	return !ps->_top;
}
// 销毁栈 
void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->_a);
	ps->_top = 0;
	ps->_capacity = 0;
}
//扩容
void StackExtend(Stack* ps){
	assert(ps);
	int extend = (ps->_capacity == 0) ? 4 : ps->_capacity * 2;
	STDataType* tmp = NULL;
	tmp=(STDataType*)realloc(ps->_a, sizeof(STDataType) * extend);
	ps->_a = tmp;
	ps->_capacity = extend;
}