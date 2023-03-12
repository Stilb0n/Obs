#include "observer.cpp"
#include <iostream>
class IFileEditor
{
	virtual ~IFileEditor() {}
	virtual void Attach(IObserver* observer) = 0;
	virtual void Detach(IObserver* observer) = 0;
	virtual void Notify() = 0;
};
