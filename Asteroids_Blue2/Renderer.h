#pragma once

#include <vulkan/vulkan.h>
#include <stdexcept>
#include <vector>

#include "Structures.h"


class Renderer
{
public:
	Renderer();
	~Renderer();

private:
	void initInstance();
	void deInitInstance();
	
	void initSurface();
	void deInitSurface();
	
	void initDevice();
	void deInitDevice();
	
	void initSwapChain();
	void deInitSwapChain();
	
	void initImageView();
	void deInitImageView();
	
	void initGraphicsPipeline();
	void deInitGraphicsPipeline();



	VkInstance instance = VK_NULL_HANDLE;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device = VK_NULL_HANDLE;

};

