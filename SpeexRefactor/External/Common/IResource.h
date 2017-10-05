/**
*	Header: IResource.h
*	Description: Interface used to release dynamic memory across dll boundary.
*
*/
#pragma once

class IResource
{
public:

	/**
	*  All objects derived from IResource must implement Release()
	*  to free all the dynamic memory allocated by that object.
	*
	**/
	virtual void Release() = 0;
};