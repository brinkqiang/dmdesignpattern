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

---
## 设计模式

| 序号 | 英文名                     | 中文名         | 解释                                                                 |
|------|------------------------------|----------------|----------------------------------------------------------------------|
| 1    | SingletonPattern             | 单例模式       | 确保一个类只有一个实例，并提供全局访问该实例的点。                                         |
| 2    | FactoryPattern               | 工厂模式       | 负责创建对象。                                                               |
| 3    | AbstractFactoryPattern       | 抽象工厂模式   | 旨在创建一个可以生产其他工厂的工厂。                                                     |
| 4    | BuilderPattern               | 建造者模式     | 将一个复杂对象的构造过程分解为多个步骤，每个步骤由单独的对象来完成。                               |
| 5    | PrototypePattern             | 原型模式       | 通过复制现有的对象来创建新的对象。                                                       |
| 6    | AdapterPattern               | 适配器模式     | 将一个类的接口转换为另一个类的接口，使原本不兼容的接口能够兼容。                                   |
| 7    | FacadePattern                | 外观模式       | 为复杂系统提供一个简单易用的接口。                                                       |
| 8    | ProxyPattern                 | 代理模式       | 为另一个对象提供一个代理或替身。                                                         |
| 9    | DecoratorPattern             | 装饰器模式     | 在不改变原有对象的基础上，为对象添加新的功能。                                               |
| 10   | BridgePattern                | 桥接模式       | 将一个类的功能和实现分离，使它们可以独立变化。                                               |
| 11   | CompositePattern             | 组合模式       | 将对象组合成树形结构，并向客户提供一致的接口用于操作。                                       |
| 12   | FlyweightPattern             | 享元模式       | 尽最大可能减少对象的数量，以减少内存使用和提高性能。                                         |
| 13   | StrategyPattern              | 策略模式       | 将算法的行为封装成一个对象，使算法可以独立于其使用它的客户而变化。                               |
| 14   | TemplatePattern              | 模板模式       | 定义一个算法的骨架，并将一些步骤延迟到子类中。                                               |
| 15   | ObserverPattern              | 观察者模式     | 定义了一种一对多的依赖关系，当一个对象的状态发生变化时，所有依赖它的对象都会得到通知。                     |
| 16   | IteratorPattern              | 迭代器模式     | 提供一种访问聚合对象中元素的迭代方式。                                                     |
| 17   | CommandPattern               | 命令模式       | 将请求封装为一个对象，使您可用不同的请求、队列或者日志来参数化客户。                               |
| 18   | ChainOfResponsibilityPattern | 责任链模式     | 将多个处理对象连接成一个链，并按顺序对请求进行处理。                                         |
| 19   | StatePattern                 | 状态模式       | 当一个对象的内部状态发生变化时，会改变它的行为。                                               |
| 20   | MediatorPattern              | 中介者模式     | 在多个对象之间建立一个松散的耦合，使它们能够以一种协调的方式进行交互。                               |
| 21   | MementoPattern               | 备忘录模式     | 记录一个对象的内部状态，以便在以后恢复到该状态。                                               |
| 22   | VisitorPattern               | 访问者模式     | 为对象结构中不同类型的元素定义不同的访问操作。                                               |
| 23   | InterpreterPattern           | 解释器模式     | 将一个语言的文法规则解释成计算机程序。                                                     |

---
## 复合设计模式 (架构模式与其他模式)

| 序号 | 英文名                       | 中文名                     | 解释                                                                                                                               |
|------|------------------------------|----------------------------|------------------------------------------------------------------------------------------------------------------------------------|
| 1    | Layered Architecture         | 分层架构                   | 一种经典的架构模式，将系统组织成多个水平层（如表现层、应用层、领域层、基础设施层）。每一层都有明确的职责，并且通常只依赖于其下一层。                                                         |
| 2    | MVC                          | 模型-视图-控制器           | 一种软件架构模式，将应用程序划分为模型、视图和控制器三个部分。模型表示应用程序的数据，视图表示应用程序的用户界面，控制器处理用户交互。MVC 通常用于构建桌面应用程序和 Web 应用程序。 |
| 3    | microservice                 | 微服务架构                 | 一种软件架构模式，SOA架构变种，其中应用程序构建为一组小型、独立的服务。微服务通常用于构建可扩展、可维护和可部署的应用程序。                                   |
| 4    | API Gateway                  | API 网关                   | 在微服务架构中，作为所有客户端请求的单一入口点。它可以处理路由、组合、安全、监控、限流等横切关注点，简化客户端与后端服务的交互。                                                                 |
| 5    | BFF (Backend For Frontend)   | 服务于前端的后端           | 一种API网关的变体，为特定的前端应用（如移动App、Web单页应用）定制后端服务。每个前端可以有自己的BFF，从而优化数据获取和交互逻辑。                                                     |
| 6    | EDA                          | 事件驱动架构               | 一种软件架构模式，其中组件通过发布和订阅事件进行通信。EDA 通常用于构建松耦合、可扩展和可维护的系统。                                                           |
| 7    | DDD (Domain-Driven Design)   | 领域驱动设计               | 一种软件开发方法论，强调通过与领域专家协作，围绕核心业务领域和领域逻辑构建丰富的模型。它使用通用语言（Ubiquitous Language）来统一团队沟通，并包含一系列战略和战术设计模式。                               |
| 8    | Hexagonal Architecture (Ports and Adapters) | 六边形架构（端口与适配器）   | 一种旨在创建松耦合应用程序组件的架构模式。它将核心应用逻辑（领域模型）与外部依赖（如UI、数据库、第三方服务）通过明确定义的端口（接口）和适配器隔离开，从而提高可测试性和灵活性。                     |
| 9    | CQRS (Command Query Responsibility Segregation) | 命令查询职责分离           | 一种将数据读取操作（查询）与数据更新操作（命令）分离的模式。这使得系统的这两部分可以独立扩展、优化和维护。常与DDD和EDA结合使用。                                                      |
| 10   | Event Sourcing               | 事件溯源                   | 一种持久化状态的方式，不直接存储对象的当前状态，而是存储导致该状态的所有领域事件的序列。系统的当前状态可以从这些事件中重建出来。常与CQRS和DDD结合使用。                                        |
| 11   | ECS                          | 实体组件系统               | 一种用于管理游戏世界中实体和组件的设计模式。实体表示游戏世界中的对象，组件表示实体的属性和行为。系统负责处理来自组件的数据。ECS 通常用于开发具有大量实体和组件的游戏世界，因为它可以提供高性能和可扩展性。 |
| 12   | FaaS                         | 前端即服务                 | 一种计算模式，其中应用程序逻辑作为服务提供。FaaS 通常用于构建无服务器应用程序，这些应用程序无需管理基础设施。 (注：更常见的对应术语是 Function as a Service)                      |

## Contacts


## Thanks
