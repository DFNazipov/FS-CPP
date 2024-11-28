#include "FSDecorator.h"

void FSDecorator::first()
{
	It->first();
	while (!It->isDone() && It->getCurrent().GetFileType() != ItFile) {
		It->next();
	}

}
void FSDecorator::next()
{
	do {
		It->next();
	} while (!It->isDone() && It->getCurrent().GetFileType() != ItFile);
}
