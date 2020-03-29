#pragma once
class BaseSolution
{
public:
	BaseSolution();
	virtual ~BaseSolution();
	virtual void run() = 0;
};

