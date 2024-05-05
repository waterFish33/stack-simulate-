#include "Stack.h"

// ��ʼ��ջ 
void StackInit(Stack* ps) {
	assert(ps);
	ps->_capacity = 0;
	ps->_a = NULL;
	StackExtend(ps);
	ps->_top = 0;

}
// ��ջ 
void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	if (ps->_capacity == ps->_top) {
		StackExtend(ps);
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ 
void StackPop(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));

	ps->_top--;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_a[ps->_top-1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps) {
	assert(ps);
	return !ps->_top;
}
// ����ջ 
void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->_a);
	ps->_top = 0;
	ps->_capacity = 0;
}
//����
void StackExtend(Stack* ps){
	assert(ps);
	int extend = (ps->_capacity == 0) ? 4 : ps->_capacity * 2;
	STDataType* tmp = NULL;
	tmp=(STDataType*)realloc(ps->_a, sizeof(STDataType) * extend);
	ps->_a = tmp;
	ps->_capacity = extend;
}