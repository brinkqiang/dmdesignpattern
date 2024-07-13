# dmdesignpattern

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[![dmdesignpattern](https://img.shields.io/badge/brinkqiang-dmdesignpattern-blue.svg?style=flat-square)](https://github.com/brinkqiang/dmdesignpattern)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/dmdesignpattern/blob/master/LICENSE)
[![blog](https://img.shields.io/badge/Author-Blog-7AD6FD.svg)](https://brinkqiang.github.io/)
[![Open Source Love](https://badges.frapsoft.com/os/v3/open-source.png)](https://github.com/brinkqiang)
[![GitHub stars](https://img.shields.io/github/stars/brinkqiang/dmdesignpattern.svg?label=Stars)](https://github.com/brinkqiang/dmdesignpattern) 
[![GitHub forks](https://img.shields.io/github/forks/brinkqiang/dmdesignpattern.svg?label=Fork)](https://github.com/brinkqiang/dmdesignpattern)

## Build status
| [Linux][lin-link] | [Mac][mac-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![mac-badge]       | ![win-badge]        |

[lin-badge]: https://github.com/brinkqiang/dmdesignpattern/workflows/linux/badge.svg "linux build status"
[lin-link]:  https://github.com/brinkqiang/dmdesignpattern/actions/workflows/linux.yml "linux build status"
[mac-badge]: https://github.com/brinkqiang/dmdesignpattern/workflows/mac/badge.svg "mac build status"
[mac-link]:  https://github.com/brinkqiang/dmdesignpattern/actions/workflows/mac.yml "mac build status"
[win-badge]: https://github.com/brinkqiang/dmdesignpattern/workflows/win/badge.svg "win build status"
[win-link]:  https://github.com/brinkqiang/dmdesignpattern/actions/workflows/win.yml "win build status"

## Intro
dmdesignpattern

- 基础设计模式

英文名	| 中文名 | 解释|
-|-|-|
SingletonPattern | 单例模式 | 确保一个类只有一个实例，并提供全局访问该实例的点。
AbstractFactoryPattern | 抽象工厂模式 | 旨在创建一个可以生产其他工厂的工厂。
AdapterPattern | 适配器模式 | 将一个类的接口转换为另一个类的接口，使原本不兼容的接口能够兼容。
BridgePattern | 桥接模式 | 将一个类的功能和实现分离，使它们可以独立变化。
BuilderPattern | 建造者模式 | 将一个复杂对象的构造过程分解为多个步骤，每个步骤由单独的对象来完成。
ChainOfResponsibilityPattern | 责任链模式 | 将多个处理对象连接成一个链，并按顺序对请求进行处理。
CommandPattern | 命令模式 | 将请求封装为一个对象，使您可用不同的请求、队列或者日志来参数化客户。
CompositePattern | 组合模式 | 将对象组合成树形结构，并向客户提供一致的接口用于操作。
DecoratorPattern | 装饰器模式 | 在不改变原有对象的基础上，为对象添加新的功能。
FacadePattern | 外观模式 | 为复杂系统提供一个简单易用的接口。
FactoryPattern | 工厂模式 | 负责创建对象。
FlyweightPattern | 享元模式 | 尽最大可能减少对象的数量，以减少内存使用和提高性能。
InterpreterPattern | 解释器模式 | 将一个语言的文法规则解释成计算机程序。
IteratorPattern | 迭代器模式 | 提供一种访问聚合对象中元素的迭代方式。
MediatorPattern | 中介者模式 | 在多个对象之间建立一个松散的耦合，使它们能够以一种协调的方式进行交互。
MementoPattern | 备忘录模式 | 记录一个对象的内部状态，以便在以后恢复到该状态。
ObserverPattern | 观察者模式 | 定义了一种一对多的依赖关系，当一个对象的状态发生变化时，所有依赖它的对象都会得到通知。
PrototypePattern | 原型模式 | 通过复制现有的对象来创建新的对象。
ProxyPattern | 代理模式 | 为另一个对象提供一个代理或替身。
SingletonPattern | 单例模式 | 确保一个类只有一个实例，并提供全局访问该实例的点。
StatePattern | 状态模式 | 当一个对象的内部状态发生变化时，会改变它的行为。
StrategyPattern | 策略模式 | 将算法的行为封装成一个对象，使算法可以独立于其使用它的客户而变化。
TemplatePattern | 模板模式 | 定义一个算法的骨架，并将一些步骤延迟到子类中。
VisitorPattern | 访问者模式 | 为对象结构中不同类型的元素定义不同的访问操作。

- 复合设计模式
  
英文名	| 中文名 | 解释|
-|-|-|
ECS | 实体组件系统 | 一种用于管理游戏世界中实体和组件的设计模式。实体表示游戏世界中的对象，组件表示实体的属性和行为。系统负责处理来自组件的数据。ECS 通常用于开发具有大量实体和组件的游戏世界，因为它可以提供高性能和可扩展性。
EDA | 事件驱动架构 | 一种软件架构模式，其中组件通过发布和订阅事件进行通信。EDA 通常用于构建松耦合、可扩展和可维护的系统。
MVC | 模型-视图-控制器 | 一种软件架构模式，将应用程序划分为模型、视图和控制器三个部分。模型表示应用程序的数据，视图表示应用程序的用户界面，控制器处理用户交互。MVC 通常用于构建桌面应用程序和 Web 应用程序。
FaaS | 前端即服务 | 一种计算模式，其中应用程序逻辑作为服务提供。FaaS 通常用于构建无服务器应用程序，这些应用程序无需管理基础设施。
microservice | 微服务架构 | 一种软件架构模式，SOA架构变种，其中应用程序构建为一组小型、独立的服务。微服务通常用于构建可扩展、可维护和可部署的应用程序。
## Contacts


## Thanks
