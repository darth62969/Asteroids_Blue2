#include "Renderer.h"

Renderer::Renderer()
{
	initInstance();
	initSurface();
	initDevice();

}

Renderer::~Renderer()
{
	deInitDevice();
	deInitInstance();
}

void Renderer::initInstance()
{
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_1;

	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create instance!");
	}
}
void Renderer::deInitInstance()
{
	vkDestroyInstance(instance, nullptr);

}

void Renderer::initSurface()
{

}

void Renderer::deInitSurface()
{
}

void Renderer::initDevice()
{
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

	physicalDevice = devices[0];

	uint32_t familyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &familyCount, nullptr);
	std::vector<VkQueueFamilyProperties> familyProperties(familyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &familyCount, familyProperties.data());

	bool found = false;
	for (uint32_t i = 0; i < familyCount; i++)
	{
		if (familyProperties[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
		{
			found = true;

		}
	}
	
	float queuePriorities[]{ 1.0f };


	VkDeviceQueueCreateInfo deviceQueueCreateInfo = {};
	deviceQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	//deviceQueueCreateInfo.queueFamilyIndex = ;
	//deviceQueueCreateInfo.queueCount = ;
	deviceQueueCreateInfo.pQueuePriorities = queuePriorities;


	VkDeviceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

	createInfo.pQueueCreateInfos = &deviceQueueCreateInfo;
	createInfo.queueCreateInfoCount = 1;

	//createInfo.pEnabledFeatures = &deviceFeatures;

	//createInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtentions.size());
	//createInfo.ppEnabledExtensionNames = deviceExtentions.data();
	

	//vkCreateDevice(physicalDevice, createInfo, nullptr, &device);
}

void Renderer::deInitDevice()
{

}

void Renderer::initSwapChain()
{
}

void Renderer::deInitSwapChain()
{
}

void Renderer::initImageView()
{
}

void Renderer::deInitImageView()
{
}

void Renderer::initGraphicsPipeline()
{
}

void Renderer::deInitGraphicsPipeline()
{
}
