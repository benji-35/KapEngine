##
## ██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
## ██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
## █████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗  
## ██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝  
## ██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
## ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
##                                                                         
## by Benjamin DELVERT

#
# DO NOT TOUCH THIS FILE
# ANY CHANGES CAN DESTROY THE PROCESS TO COMPILE
#

# PATHES ENGINE

ENGINE_PATH_COMPONENTS		=	Components/
ENGINE_PATH_COMPONENT		= 	Component/
ENGINE_PATH_GAMEOBJECTS		=	GameObject/

ENGINE_PATH_ENGINE			=	Engine/
ENGINE_PATH_ERRORS			=	Errors/

ENGINE_PATH_SCENE			=	SceneManagement/Scene/
ENGINE_PATH_SCENEMANAGER	=	SceneManagement/SceneManager/

ENGINE_PATH_TOOLS			=	Tools/
ENGINE_PATH_DEBUG			=	Debug/

ENGINE_PATH_GRAPHICAL		=	GraphicalLib/

ENGINE_PATH_INPUTS			=	Events/Input/
ENGINE_PATH_MOUSE			=	Events/Mouse/
ENGINE_PATH_EV_MANAGER		=	Events/Manager/

ENGINE_PATH_LEGACY_GRAPHICAL	=	Legacy/Graphical/

ENGINE_PATH_EVENT_ACTION	=	Events/Action/

ENGINE_PATH_TIME			=	Time/

ENGINE_PATH_ENTITY			=	Entity/

ENGINE_PATH_OPERATION		=	SpecialOperation/
ENGINE_PATH_ASYNC_OPERATION	=	$(ENGINE_PATH_OPERATION)AsyncOperation/
ENGINE_PATH_SYNC_OPERATION	=	$(ENGINE_PATH_OPERATION)SyncOperation/

# INCLUDES DEFINE

ENGINE_INCLUDES	=	-I $(ENGINE_PATH_COMPONENT)								\
					-I $(ENGINE_PATH_COMPONENTS)							\
					-I $(ENGINE_PATH_ENGINE)								\
					-I $(ENGINE_PATH_ERRORS)								\
					-I $(ENGINE_PATH_GAMEOBJECTS)							\
					-I $(ENGINE_PATH_SCENE)									\
					-I $(ENGINE_PATH_SCENEMANAGER)							\
					-I $(ENGINE_PATH_TOOLS)									\
					-I $(ENGINE_PATH_DEBUG)									\
					-I $(ENGINE_PATH_GRAPHICAL)								\
					-I $(ENGINE_PATH_INPUTS)								\
					-I $(ENGINE_PATH_MOUSE)									\
					-I $(ENGINE_PATH_EV_MANAGER)							\
					-I $(ENGINE_PATH_COMPONENTS)Transform					\
					-I $(ENGINE_PATH_COMPONENTS)Camera						\
					-I $(ENGINE_PATH_LEGACY_GRAPHICAL)						\
					-I $(ENGINE_PATH_EVENT_ACTION)							\
					-I $(ENGINE_PATH_TIME)									\
					-I $(ENGINE_PATH_ASYNC_OPERATION)						\
					-I $(ENGINE_PATH_SYNC_OPERATION)						\
					-I $(ENGINE_PATH_ENTITY)								\


PATH_FOR_GAME_TO_ENGINE	=	../KapEngine/

ENGINE_INCLUDES_EG	=	-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_COMPONENT)							\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_COMPONENTS)							\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_ENGINE)								\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_ERRORS)								\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_GAMEOBJECTS)							\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_SCENE)								\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_SCENEMANAGER)						\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_TOOLS)								\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_DEBUG)								\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_GRAPHICAL)							\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_INPUTS)								\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_MOUSE)								\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_EV_MANAGER)							\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_COMPONENTS)Transform					\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_COMPONENTS)Camera					\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_LEGACY_GRAPHICAL)					\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_EVENT_ACTION)						\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_TIME)								\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_ASYNC_OPERATION)						\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_SYNC_OPERATION)						\
						-I $(PATH_FOR_GAME_TO_ENGINE)$(ENGINE_PATH_ENTITY)								\

INCLUDE_UTILS = -pthread

CPP_VERSION =	-std=c++17
